local atmega = {}
SAMPLE_TIME = Target.Variables.SAMPLE_TIME
Clock_Speed = 16000000 --clock speed of atmega328p, may differ for other boards
prescaler = "NIL"
COMPA = 65536 --COMPA = 65536 maximum value of output compare register OCR1A
MINIMUM_SAMPLE = 1.25e-07
MAXIMUM_SAMPLE = 4.194368

freq1= Clock_Speed/1
freq8= Clock_Speed/8
freq64= Clock_Speed/64
freq256= Clock_Speed/256
freq1024= Clock_Speed/1024

period1 = 1.0/freq1
period8 = 1.0/freq8
period64 = 1.0/freq64
period256 = 1.0/freq256
period1024 = 1.0/freq1024

count1 = SAMPLE_TIME/period1-1
count8 = SAMPLE_TIME/period8-1
count64 = SAMPLE_TIME/period64-1
count256 = SAMPLE_TIME/period256-1
count1024 = SAMPLE_TIME/period1024-1

local copy_file2 = function (src, dest, subs)
  local file = io.open(src, "rb")
  local src_content = file:read("*all")
	src_content = string.gsub( src_content, "\r", "")
  io.close(file)
  local dest_content

  file = io.open(dest, "rb")
  if(file == nil) then
    dest_content = nil
  else
    dest_content = file:read("*all")
    io.close(file)
  end



  if subs ~= nil then
  	for _,v in pairs(subs) do
  		local before = v["before"]
  		local after = v["after"]
  		src_content = string.gsub( src_content, before, after)
	end
  end

  if not (src_content == dest_content) then
    local file = io.open(dest, "w")
    io.output(file)
    io.write(src_content)
    file.close()
  end
end


local function count()
  if count1 < COMPA then return count1

  elseif count8 < COMPA then return count8

  elseif count64 < COMPA then return count64

  elseif count256 < COMPA then return count256

  elseif count1024 < COMPA then return count1024

  else return 0

  end
end

--atmega.count = count
local count = math.floor(count())

local function prescale()
  if count1 < COMPA then
    prescaler = 1
    return prescaler
  elseif count8 < COMPA then
    prescaler = 8
    return prescaler
  elseif count64 < COMPA then
    prescaler = 64
    return prescaler
  elseif count256 < COMPA then
    prescaler = 256
    return prescaler
  elseif count1024 < COMPA then
    prescaler = 1024
    return prescaler
  else return 0
  end
end

--atmega.prescale = prescale
local prescale = prescale()

function settings(digiBlocks)
  local settings = io.open(Target.Variables.TARGET_ROOT .. "/templates/settings.h", "w")
  settings:write("#define SAMPLE_TIME " .. Target.Variables.SAMPLE_TIME)
  settings:write("\n#define prescaler " .. prescale)
  settings:write("\n#define count " .. count)
  settings:write("\n#define digitalPins " .. digiBlocks)
  settings:write("\n#define MINIMUM_SAMPLE 1.25e-07")
  settings:write("\n#define MAXIMUM_SAMPLE 4.194368")

  settings:write("\n\n#define start_time 0")--.. Target.Variables.start_time)
  --settings:write("\n#define Base_H " .. Target.Variables.BASE_NAME .. ".h")
  settings:write("\n#define Base_Step " .. Target.Variables.BASE_NAME .. "_step()")
  settings:write("\n#define Base_Init " .. Target.Variables.BASE_NAME .. "_initialize(start_time)")

  settings:write("\n\nextern void " .. Target.Variables.BASE_NAME .. "_step();")
  settings:write("\nextern void " .. Target.Variables.BASE_NAME .. "_initialize(double time);")
  settings:write("\nextern void " .. Target.Variables.BASE_NAME .. "_terminate();")
  io.close(settings)
  copy_file2(Target.Variables.TARGET_ROOT .. "/templates/settings.h", Target.Variables.installDir .. "/settings.h")


  if SAMPLE_TIME > MAXIMUM_SAMPLE then return ("Discretization step size too big, maximum is: " .. MAXIMUM_SAMPLE)
  else if SAMPLE_TIME < MINIMUM_SAMPLE then return ("Discretization step size too small, minimum is: " .. MINIMUM_SAMPLE)
  else return false
  end
end
end

--atmega.settings = settings

return atmega
