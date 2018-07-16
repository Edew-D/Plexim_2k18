local Math = {}
SAMPLE_TIME = Target.Variables.SAMPLE_TIME
Clock_Speed = 16000000 --clock speed of atmega328p, may differ for other boards
multiplier = 1000000
base = 16.0
prescaler = "NIL"
COMPA = 65536 --COMPA = 65536 maximum value of output compare register OCR1A

freq1= base/1*multiplier
freq8= base/8*multiplier
freq64= base/64*multiplier
freq256= base/256*multiplier
freq1024= base/1024*multiplier

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

local function count()
  if count1 < COMPA then return count1
  elseif count8 < COMPA then return count8

  elseif count64 < COMPA then return count64

  elseif count256 < COMPA then return count256

  elseif count1024 < COMPA then return count1024

  else return "Error, Step Size too big"
  end
end
math.count = count

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
  end
end
math.prescale = prescale

return math
