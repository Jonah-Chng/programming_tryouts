# https://www.programiz.com/python-programming/property

# The below code takes a temperature in celsius and converts to fahrenheit
# An additional value constraint is placed in, which causes issues:
#   - All calls like human.temperature = 37 must be converted to human =Celsius(37)
#   - All calls like print(human.temperature) must be changed to print(human.get_temperature())

# Making Getters and Setter methods
class Celsius:
    def __init__(self, temperature=0):
        # Originaaly self.temperature = temperature
        self.set_temperature(temperature)

    def to_fahrenheit(self):
        return (self.get_temperature() * 1.8) + 32

    # getter method
    def get_temperature(self):
        return self._temperature # <- Private variable

    # setter method
    def set_temperature(self, value):
        if value < -273.15:
            raise ValueError("Temperature below -273.15 is not possible.")
        self._temperature = value

# Create a new object, set_temperature() internally called by __init__
human = Celsius(37) # Originally human.temperature = 37

# Get the temperature attribute via a getter
print(human.get_temperature())

# Get the to_fahrenheit method, get_temperature() called by the method itself
print(human.to_fahrenheit())

# new constraint implementation
human.set_temperature(-300)

# Get the to_fahreheit method
print(human.to_fahrenheit())