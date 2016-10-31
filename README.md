# labs
## Aesthetic Actuation Lab
In this lab, we revist Day 1 of physical computing. Can an Arduino form a deeper conversation than a "Hello World"?
To investigate this, the aesthetic actuation code provides a sandbox for exploring different behaviors with LEDs. 
How might you communicate the following behaviors with three LEDs. The code leaves areas for your to add your own interpretations. 
* UTTER FAILURE (q)
* ERROR (w)
* WARNING (e)
* CALM (r)
* VICTORY! (t)

In the serial console interface, you can type in a character command to trigger the behavior. n.b. remember to specify that your carriage return should be "Newline"; its on the bottom right of the serial console interface next to baudrate. 

Give 'o' a try. All your leds should turn on. ('f' turns them off). 
The characters next to each behavior trigger them. 

Use this interface to understand how these behavior differ from each other. 
I added a potentiometer to the sketch to showcase how we can use this character API to design interaction aesthetics. 
In this case, the goal was a calm aesthetic. 
My implemention did the following: 
* Utter failure - constant red light
* Error - blinking red light for 1s
* Warning - solid green light
* Calm - solid purple light
* Victory - all lights on

# Interaction Design with a Potentiometer for a Calm Turn Aesthetic (Potential Solution)
I bound these behaviors to the potentiometer values, keeping track of a delta variable (how much change was observed from one time step to the other). 
We maintained a calm behavior for low values of delta.
If it reached the middle range of delta, a warning behavior would be triggered. 
For large deltas, and error behavior would be triggered and a `strikes` variable would be decremented. 
If you have not more strike, an utter failure behavior would be called. 
Otherwise, if you reached the full turn of a potentiometer, a victory variable would be triggered. 

### Hookup Diagram 
https://github.com/cearto/labs/blob/master/Aesthetic%20Actuation%20Lab.png
