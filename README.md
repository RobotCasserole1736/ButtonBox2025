# Button Box 2025

Four buttons, plus a 12-position switch. Two TBD slots, likely to be switches at some point? Maybe? Designed for selecting what we want the robot to do next. Critically, not for saying _how_ the robot does something, that's an XBOX controller.

# BOM

[Screw Terminal Headers](https://www.amazon.com/gp/product/B08B3P8BF3/ref=ppx_yo_dt_b_asin_title_o02_s00?ie=UTF8&psc=1)
[Smaller screw terminal headers](https://www.amazon.com/dp/B09F6TC7RP?ref=ppx_yo2ov_dt_b_fed_asin_title)
[buttons with prewired leads](https://www.amazon.com/dp/B083JWJPW5?ref=ppx_yo2ov_dt_b_fed_asin_title&th=1)
[12-position switch](https://www.amazon.com/dp/B07CG9RPKY?ref=ppx_yo2ov_dt_b_fed_asin_title)
[Arduino Micro](https://www.amazon.com/dp/B0D83FBYPD?ref=ppx_yo2ov_dt_b_fed_asin_title)
[USB C panel connector](https://www.amazon.com/gp/product/B09HWSFRP1/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1)
[Chicken head knobs, in red.](https://www.amazon.com/dp/B0CTK8KTCY?ref=ppx_yo2ov_dt_b_fed_asin_title&th=1)
Various lengths of wire and solder from chris's house.

# In Robot Code

See `GenericHID` - https://docs.wpilib.org/en/stable/docs/software/basic-programming/joystick.html#button-usage

Use `getRawButton()` to get each state. 

18 buttons are enumerated. 

The chickenhead knob may be thought of as 12 buttons, only one of which is pressed at a time (generally)

Each pushbutton is either pressed or not pressed.

Each switch (future) is either on or off.

