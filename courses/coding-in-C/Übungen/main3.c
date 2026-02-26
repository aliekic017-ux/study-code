#include <stdio.h>
#include <stdlib.h>


struct measurement
{
    float time;
    float temp;
};

struct Sensor
{
    int id;
    float threshold;
    struct measurement data[10];
    int alarm[10];

};

void alarm_generation(struct Sensor *sensor)
{
    
    for (int h = 0; h < 10; h++)
    {
        if (sensor->data[h].temp > sensor->threshold)
        {
            sensor->alarm[h] = 1;
    
            
        }
        else
        {
            sensor->alarm[h] = 0;
            printf("%d", sensor->alarm[h]);
        }
        
    }
}

void alarm_time_intervalls (struct Sensor *sensor)
{
    int actvie = 0; 
    float starttime;
    float endtime;

    for (int g= 0; g < 10 ; g++)
    {
        if (actvie == 0 && sensor->alarm[g] == 1)
        {
            starttime = sensor->data[g].time;
            actvie = 1;
        }
        if (actvie == 1 && sensor->alarm[g] == 0 )
        {
            endtime = sensor->data[g-1].time;
            actvie = 0;

            printf("Starttime: %.2f  Endtime: %.2f\n", starttime, endtime);
        }
    }
    if (actvie ==1)
    {
        endtime = sensor->data[9].time;
        actvie = 0;
        printf("Starttime: %.2f  Endtime: %2.f", starttime, endtime);
    }
    
}

void fusion (struct Sensor *sensor, struct Sensor *sensor2, int fusion[10])
{
    
    for (int h = 0; h < 10; h++)
    {
        if (sensor->alarm[h] == 1 && sensor2->alarm[h] == 1)
        {
            fusion[h] = 1;
            printf("Fusion: %d", fusion[h]);
            

        }
        
    }
}

void fusion_zeit_intervalls(struct Sensor *sensor, struct Sensor *sensor2)
{
    int active = 0;
    float starttime;
    float endtime;

    for (int l = 0; l < 10; l++)
    {
        if (active == 0 && sensor->alarm[l] == 1 && sensor2->alarm[l] == 1)
        {
            starttime = sensor->data[l].time;
            active = 1;
        }
        if (active == 1 && !(sensor->alarm[l] == 1 && sensor2->alarm[l] == 1))
        {
            endtime = sensor->data[l-1].time;
            active = 0;

            printf("Starttime_Fusion: %.2f  Endtime_Fusiom: %.2f", starttime, endtime);
        }
    }
    if (active == 1)
    {
        endtime = sensor->data[9].time;
        printf("Starttime_Fusion: %.2f  Endtime_Fusion: %.2f", starttime, endtime);
    }
}
    
int main()
{
    struct Sensor Var1 = {12, 12};
    struct Sensor Var2 = {21, 19};

    int f_usion[10];

    Var1.data[0].temp = 34;
    Var1.data[1].temp = 45;
    Var1.data[2].temp = 67;
    Var1.data[3].temp = 87;
    Var1.data[4].temp = 80;
    Var1.data[5].temp = 45;
    Var1.data[6].temp = 54;
    Var1.data[7].temp = 57;
    Var1.data[8].temp = 22;
    Var1.data[9].temp = 34;

    Var2.data[0].temp = 72;
    Var2.data[1].temp = 56;
    Var2.data[2].temp = 67;
    Var2.data[3].temp = 78;
    Var2.data[4].temp = 90;
    Var2.data[5].temp = 45;
    Var2.data[6].temp = 32;
    Var2.data[7].temp = 56;
    Var2.data[8].temp = 12;
    Var2.data[9].temp = 8;


    Var1.data[0].time = 0.5;
    Var1.data[1].time = 0.6;
    Var1.data[2].time = 0.7;
    Var1.data[3].time = 0.8;
    Var1.data[4].time = 0.9;
    Var1.data[5].time = 1.0;
    Var1.data[6].time = 1.1;
    Var1.data[7].time = 1.2;
    Var1.data[8].time = 1.3;
    Var1.data[9].time = 1.4;

    Var2.data[0].time = 0.5;
    Var2.data[1].time = 0.6;
    Var2.data[2].time = 0.7;
    Var2.data[3].time = 0.8;
    Var2.data[4].time = 0.9;
    Var2.data[5].time = 1.0;
    Var2.data[6].time = 1.1;
    Var2.data[7].time = 1.2;
    Var2.data[8].time = 1.3;
    Var2.data[9].time = 1.4;



printf("Var1_Detection: \n");
alarm_generation(&Var1);


printf("\nVar2_Detection: \n");
alarm_generation(&Var2);

alarm_time_intervalls(&Var1);
alarm_time_intervalls(&Var2);

fusion(&Var1, &Var1, f_usion);




    return 0;
}




