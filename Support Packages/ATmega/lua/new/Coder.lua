local Coder = { }
local arduino = require("arduino")

---local prescale = maths.prescale()
--local count = maths.count()
local function has_value (tab, val)
    for index, value in ipairs(tab) do
        if value == val then
            return true
        end
    end
    return false
end

copy_file = function (src, dest, subs)
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
    --io.input():close()
    file.close()
  end
end


local Registry = {
  NumDigitalBlocks = 0,
  timers = {0, 1, 2}
}

function Coder.RegisterDigitalBlock()
  local ret = Registry.NumDigitalBlocks
  Registry.NumDigitalBlocks = ret+1
  return ret
end

function Coder.RegisterTimer(timer)

  local ret2 = Registry.timers
  if has_value(ret2, timer - 1) then
    table.remove(ret2, timer)
    Registry.timers = ret2
  else return "Error"
  end

  if has_value(ret2, 1 ) then return RegisterTimer(2) --checks if timer1 is in use, prioretizes timer 1
  elseif has_value(ret2, 0) then return RegisterTimer(1)
  elseif has_value(ret2, 2) then return RegisterTimer(3)
  end
end

function Coder.RegisterPwmOutBlock(pwm)
  local pwm_pins = {3, 5, 6, 9, 10, 11}
  local ret1
  if has_value(pwm_pins, pwm) then
    ret1 = Coder.RegisterDigitalBlock()
  else return "Error"
  end
  return ret1
end


function Coder.Initialize()
  local Resources = ResourceList:new()
  local Include = {}
  local Declarations = {}
  local PreInitCode = {}
  local PostInitCode = {}
  local TerminateCode = {}

  local dummy = print -- dummy access to global environment ("attempt to call a table value" workaround)

  Resources:add("GPIO", 0, 199)
  Resources:add("PWM_Pin", 3, 3)
  Resources:add("PWM_Pin", 5, 6)
  Resources:add("PWM_Pin", 9, 11)
  --Resources:add("Timer", 0, 2)
  --[[Registry.PwmGpio[3] = 3
  Registry.PwmGpio[5] = 5
  Registry.PwmGpio[6] = 6
  --Registry.PwmGpio[4] = 9  Timer 1 Can't use yet
  --Registry.PwmGpio[5] = 10 Timer1 Can't use yet
  Registry.PwmGpio[11] = 11]]


  return {
     Declarations = Declarations,
     PreInitCode = PreInitCode,
     PostInitCode = PostInitCode,
     TerminateCode = TerminateCode,
     Include = Include,
     Resources = Resources
  }
end


function Coder.Finalize()
  local Include = {}
  local Declarations = {}
  local PreInitCode = {}
  local PostInitCode = {}
  local TerminateCode = {}

  local digiBlocks = tostring(Coder.RegisterDigitalBlock())
  local assert = settings(digiBlocks)
  if assert ~= false then return assert end

  local dict = {}
  table.insert(dict, {before = "|>BASE_NAME<|", after = Target.Variables.BASE_NAME})
  table.insert(dict, {before = "|>INSTALL_DIR<|", after = Target.Variables.installDir})
  copy_file(Target.Variables.TARGET_ROOT .. "/templates/install.mk", Target.Variables.BUILD_ROOT .. "/" .. Target.Variables.BASE_NAME .. ".mk", dict)


  return {
     Declarations = Declarations,
     PreInitCode = PreInitCode,
     PostInitCode = PostInitCode,
     TerminateCode = TerminateCode,
     Include = Include,
     Resources = Resources
  }
end

return Coder
