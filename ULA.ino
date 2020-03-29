int s0 = 13, s1 = 12, s2 = 11, s3 = 10;
int s0_volt = 0,s1_volt = 0,s2_volt = 0,s3_volt = 0;
int e1, e2, e3;

void setup(){
    Serial.begin(9600);
    pinMode(s0,OUTPUT);
    pinMode(s1,OUTPUT);
    pinMode(s2,OUTPUT);
    pinMode(s3,OUTPUT);
}//end of setup

void loop(){
    if(Serial.avaliable() > 0){
        e1 = Serial.parseInt();
        e2 = Serial.parseInt();
        e3 = Serial.parseInt();
        if(Serial.read() == '\n'){
            switch(e3){
                case 0:
                    traduz(0);
                    break;
                case 1:
                    traduz(1);
                    break;
                case 2:
                    traduz(~e1);
                    break;
                case 3:
                    traduz(~e2);
                    break;
                case 4:
                    traduz(e1|e2);
                    break;
                case 5:
                    traduz(e1&e2);
                    break;
                case 6:
                    traduz(e1^e2);
                    break;
                case 7:
                    traduz(~(e1&e2));
                    break;
                case 8:
                    traduz(~(e1|e2));
                    break;
                case 9:
                    traduz(~(e1^e2));
                    break;
                case 10:
                    traduz((~e1)|e2);
                    break;
                case 11:
                    traduz(e1|(~e2));
                    break;
                case 12:
                    traduz((~e1)&e2);
                    break;
                case 13:
                    traduz(e1&(~e2));
                    break;
                case 14:
                    traduz((~e1)&(~e2));
                    break;
                case 15:
                    break;
            }//end of switch
            digitalWrite(s0,s0_volt);
            digitalWrite(s1,s1_volt);
            digitalWrite(s2,s2_volt);
            digitalWrite(s3,s3_volt);
        }//end of if
    }//end of if
}//end of loop

void traduz(int entrada){
    int menu = entrada & 0xF;
    switch(menu){
        case 0:
            s0_volt = 0;
            s1_volt = 0;
            s2_volt = 0;
            s3_volt = 0;
            break;
        case 1:
            s0_volt = 0;
            s1_volt = 0;
            s2_volt = 0;
            s3_volt = 1;
            break;
        case 2:
            s0_volt = 0;
            s1_volt = 0;
            s2_volt = 1;
            s3_volt = 0;
            break;
        case 3:
            s0_volt = 0;
            s1_volt = 0;
            s2_volt = 1;
            s3_volt = 1;
            break;
        case 4:
            s0_volt = 0;
            s1_volt = 1;
            s2_volt = 0;
            s3_volt = 0;
            break;
        case 5:
            s0_volt = 0;
            s1_volt = 1;
            s2_volt = 0;
            s3_volt = 1;
            break;
        case 6:
            s0_volt = 0;
            s1_volt = 1;
            s2_volt = 1;
            s3_volt = 0;
            break;
        case 7:
            s0_volt = 0;
            s1_volt = 1;
            s2_volt = 1;
            s3_volt = 1;
            break;
        case 8:
            s0_volt = 1;
            s1_volt = 0;
            s2_volt = 0;
            s3_volt = 0;
            break;
        case 9:
            s0_volt = 1;
            s1_volt = 0;
            s2_volt = 0;
            s3_volt = 1;
            break;
        case 10:
            s0_volt = 1;
            s1_volt = 0;
            s2_volt = 1;
            s3_volt = 0;
            break;
        case 11:
            s0_volt = 1;
            s1_volt = 0;
            s2_volt = 1;
            s3_volt = 1;
            break;
        case 12:
            s0_volt = 1;
            s1_volt = 1;
            s2_volt = 0;
            s3_volt = 0;
            break;
        case 13:
            s0_volt = 1;
            s1_volt = 1;
            s2_volt = 0;
            s3_volt = 1;
            break;
        case 14:
            s0_volt = 1;
            s1_volt = 1;
            s2_volt = 1;
            s3_volt = 0;
            break;
        case 15:
            s0_volt = 1;
            s1_volt = 1;
            s2_volt = 1;
            s3_volt = 1;
            break;
    }//end of switch
}//end of traduz
