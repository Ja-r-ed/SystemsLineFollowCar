
#define enA 11//Enable1 L293 Pin enA 
#define in1 6 //Motor1  L293 Pin in1 
#define in2 3 //Motor1  L293 Pin in1 
#define in3 9 //Motor2  L293 Pin in1 
#define in4 10 //Motor2  L293 Pin in1 
#define enB 5 //Enable2 L293 Pin enB 
#define R_S 7 //ir sensor Right
#define L_S 12 //ir sensor Left
#define M_S 2//ir sensor Middle

void setup(){ 
pinMode(R_S, INPUT); 
pinMode(L_S, INPUT); 
pinMode(M_S, INPUT);
pinMode(enA, OUTPUT); 
pinMode(in1, OUTPUT); 
pinMode(in2, OUTPUT); 
pinMode(in3, OUTPUT); 
pinMode(in4, OUTPUT); 
pinMode(enB, OUTPUT);
digitalWrite(enA, HIGH); 
digitalWrite(enB, HIGH);

delay(1000);
}
void loop(){
    float error = 0;
    float leftSensor = digitalRead(L_S);
    float rightSensor = digitalRead(R_S);
    float middleSensor = digitalRead(M_S);
    error = (rightSensor - leftSensor); //*(1-middleSensor);
    float pidValue = pidController(error);
    drive(pidValue);
}

void drive(float direction) {
    // Clamp direction to the range [-1, 1]
    if (direction > 1) direction = 1;
    if (direction < -1) direction = -1;

    // Calculate motor speeds based on direction and speed
    float rightMotorSpeed = 1 * (1 - direction);
    float leftMotorSpeed = 1 * (1 + direction);

    // Set motor speeds
    analogWrite(enA, (int)(rightMotorSpeed * 255)); // Right motor speed out of 255
    analogWrite(enB, (int)(leftMotorSpeed * 255));  // Left motor speed

    // Set motor directions
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);


      digitalWrite(in4, HIGH);
      digitalWrite(in3, LOW);
}

float pidController(float error) {
    float kp = 1;
    float ki = 0.;
    float kd = 0;
    static float previousError = 0.0;
    static float integral = 0.0;

    // Calculate proportional term
    float proportional = kp * error;

    // Calculate integral term
    integral += error;
    float integralTerm = ki * integral;

    // Calculate derivative term
    float derivative = kd * (error - previousError);

    // Update previous error
    previousError = error;

    // Calculate PID output
    float pidOut = proportional + integralTerm + derivative;

    // Clamp PID output to the range [-1, 1]
    if (pidOut > 1) pidOut = 1;
    if (pidOut < -1) pidOut = -1;

    return pidOut;
}