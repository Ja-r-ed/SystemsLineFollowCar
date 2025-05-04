// Arduino Line Follower Robot Code
#define enA 11 // Enable1 L293 Pin enA
#define in1 6  // Motor1 L293 Pin in1
#define in2 3  // Motor1 L293 Pin in2
#define in3 9  // Motor2 L293 Pin in3
#define in4 10 // Motor2 L293 Pin in4
#define enB 5  // Enable2 L293 Pin enB
#define R_S 4  // IR sensor Right
#define L_S 2  // IR sensor Left
#define M_S 12 // IR sensor Middle

void setup() {
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

void loop() {
    // Set motors to drive forward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);

    // Set speed using PWM
    analogWrite(enA, 150); // Speed for Motor1 (0-255)
    analogWrite(enB, 150); // Speed for Motor2 (0-255)
}
