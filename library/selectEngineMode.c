#include <stdio.h>
#include <stdlib.h>
#include <enums.h>

//#define EngineTemperatureControllerstate 

struct TemperatureMode{
    int Temperature;
    struct TemperatureMode *next;
};

void StartEngine(){
    struct TemperatureMode *room = malloc(sizeof(struct TemperatureMode));
    struct TemperatureMode *car  = malloc(sizeof(struct TemperatureMode));

    room->Temperature = 0;
    car->Temperature = 0;

    room->next = car;
    car->next = NULL;

    int ACState=Off;
    int EngineControllerState=Off;
    int roomTemperatureSensorVal=0;
    int carTemperatureSensorVal=0;
    int VelocitySensorVal=0;


    char SensorChoice;
    while(1){
        printf("\nThe sensor menu : \n");
        printf("a. Stop Engine \nb. Set tarffic light Color \nc. Set room Temperature \nd. Display systems state\n");
        printf("your choice: ");
        scanf(" %c", &SensorChoice);
        printf("\n");
        if (SensorChoice=='a'||SensorChoice=='A')
        {
            printf("The engine is stopped\n");
            break;
        }
        
        else if(SensorChoice=='b'||SensorChoice=='B'){
            int TrafficLightColor;
            printf("The traffic light is selected\n");
            printf("Please state which color: \n1-100 Km/h \n2-30 Km/h\n3- 0 Km/h\n");
            printf("your choice: ");
            scanf("%d", &TrafficLightColor);
            printf("\n");
            if (TrafficLightColor==G){
                VelocitySensorVal=100;
                printf("The traffic light is set to 30 Km/h\n");
            }
            else if(TrafficLightColor==O){
                VelocitySensorVal=30;
                printf("The traffic light is set to 100 Km/h\n");
            }
            else if(TrafficLightColor==R){
                VelocitySensorVal=0;
                printf("The traffic light is set to 0 Km/h\n");
            }
            else{
                printf("Please enter a valid choice\n");
            }

        }
        
        else if(SensorChoice=='c'||SensorChoice=='C'){
            char TemperatureChoice;
            struct TemperatureMode *TemperatureMode = room;      
            printf("The temperature is selected\n");
            printf("Please state which Temperature state: \na-Room Temperature \n");
            #ifdef EngineTemperatureControllerstate
                printf("b-Car Temperature\n");
            #endif
            printf("your choice: ");
            scanf(" %c", &TemperatureChoice);
            printf("\n");

            if (TemperatureChoice=='a'||TemperatureChoice=='A'){
                roomTemperatureSensorVal= rand() % 50 + 1;
                if (roomTemperatureSensorVal<10){
                    printf("The room temperature is:%d ℃\n", roomTemperatureSensorVal);
                    ACState = on;
                    TemperatureMode->Temperature = 20;
                }
                else if(roomTemperatureSensorVal>30){
                    ACState = on;
                    printf("The room temperature is set to %d ℃\n", roomTemperatureSensorVal);
                    TemperatureMode->Temperature = 20;
                }
                else{
                    ACState = Off;
                    printf("The room temperature is set to %d ℃\n", roomTemperatureSensorVal);
                    TemperatureMode->Temperature = 0;
                }
            }
            
            #ifdef EngineTemperatureControllerstate
            else if(TemperatureChoice=='b'||TemperatureChoice=='B'){
                carTemperatureSensorVal= rand() % 150 + 1;
                if (carTemperatureSensorVal<100){
                    printf("The car temperature is:%d ℃\n", carTemperatureSensorVal);
                    EngineControllerState = on;
                    TemperatureMode->next->Temperature = 125;
                }
                
                else if(carTemperatureSensorVal>150){
                    EngineControllerState = on;
                    printf("The car temperature is set to %d ℃\n", carTemperatureSensorVal);
                    TemperatureMode->next->Temperature = 125;
                }
                
                else{
                    EngineControllerState = Off;
                    printf("The car temperature is set to %d ℃\n", carTemperatureSensorVal);
                    TemperatureMode->next->Temperature = 0;
                }
            }
            #endif

            if (VelocitySensorVal==30){
                TemperatureMode->Temperature = (5/4)*roomTemperatureSensorVal+1;

                #ifdef EngineTemperatureControllerstate
                    TemperatureMode->next->Temperature = (5/4)*carTemperatureSensorVal+1;
                #endif
                
                if (ACState==Off){
                    ACState = on;
                }
                
                #ifdef EngineTemperatureControllerstate
                if (EngineControllerState==Off){
                    EngineControllerState = on;
                }
                #endif
            }

        }   
        
        else if(SensorChoice=='d'||SensorChoice=='D'){
            printf("The system state is:\n");
            printf("The AC is: %d\n", ACState);
            #ifdef EngineControllerState
            printf("The Engine Controller is: %d\n", EngineControllerState);
            #endif
            printf("The room temperature is: %d ℃\n", room->Temperature);
            #ifdef EngineTemperatureControllerstate
            printf("The car temperature is: %d ℃\n", car->Temperature);
            #endif
            printf("The velocity is: %d Km/h\n", VelocitySensorVal);
            printf("\n");
        }

        else{
            printf("Please enter a valid choice\n");
        }
    }
}

void SelectEngineMode(){
    char engineChoice;
    while (1){
        printf("Welcome to the car system!(please write the charchter of the state)\n");
        printf("a. Start engine\nb. Stop the engine\nc. Quit the system\n");
        printf("your choice: ");
        scanf(" %c", &engineChoice);
        printf("\n");
        if(engineChoice=='a'||engineChoice=='A'){
            printf("The engine is started\n");
            StartEngine();
        }
        else if(engineChoice=='b'||engineChoice=='B'){
            printf("The engine is stopped\n");
        }
        else if(engineChoice=='c'||engineChoice=='C'){
            printf("The system is quited\n");
            exit(0);
        }
        else{
            printf("\nPlease enter a valid choice\n \n");
        }
    }
}