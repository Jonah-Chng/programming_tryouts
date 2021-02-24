# https://www.programiz.com/python-programming/property

# The below code is backwards compatible:
#   - human.temperature works, so does human=Celsius(37)
#   - print(human.temperature) works

# using property class
class Celsius:
    def __init__(self, temperature=0):
        self.temperature = temperature

    def to_fahrenheit(self):
        return (self.temperature * 1.8) + 32

    # getter
    def get_temperature(self):
        print("Getting value...")
        return self._temperature

    # setter
    def set_temperature(self, value):
        print("Setting value...")
        if value < -273.15:
            raise ValueError("Temperature below -273.15 is not possible")
        self._temperature = value

    # By using property, we can see that no modification is required in the 
    # implementation of the value constraint. Thus, our implementation is backward compatible.

    # creating a property object
    temperature = property(get_temperature, set_temperature)
    # The actual temperature value is stored in the private _temperature variable. 
    # The temperature attribute is a property object which provides an 
    # interface to this private variable.

class checking_access_to:
    def __init__(self, celsius):
        self.something = celsius.another_temperature
        print("Checking access to variable temperature",self.something)

# Create a new object
human = Celsius(37) # <- Everytime temperature is set, even with initializing the variable, set_temperature is called
print("Human's dict",human.__dict__)

# Get the temperature attribute via a getter
print(human.temperature)

# Get the to_fahrenheit method, get_temperature() called by the method itself
print(human.to_fahrenheit())

# new constraint implementation
human.set_temperature(-300)