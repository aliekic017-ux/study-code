#include <stdio.h>
#include <stdlib.h>

#define N 10

void print_intervalls (int signal[], float time [], int n)
{
    int active = 0; 
    float timestart;
    float timeend;

    for (int i = 0; i < n; i++)
    {
        if (active == 0 && signal[i] == 1)
        {
            timestart = time[i];
            active = 1;
        }
        else if (active == 1 && signal[i] == 0)
        {
            timeend = time[i-1];
            active = 0;
            printf("Start: %.2f  End: %.2f\n", timestart, timeend);
        }
    }
    if (active == 1)
    {
        timeend = time[n-1];
        printf("Start: %.2f  End: %.2f\n", timestart, timeend);
    }
    
}

void compute_detection (double probability[], int signal[], int n, double threshold)
{
    for (int k = 0; k < n ; k++)
    {
        if (probability[k] > threshold ) // probability ist die Wahrscheinlichkeit, dass ein Objekt da ist
        {
            signal [k] = 1;
        }
        else
        {
            signal[k] = 0; 
        }
    }
}

void compute_fusion (int det1[], int det2[], int fused[], int n)
{
    for (int l  = 0; l < n; l++)
    {
        if (det1[l] == 1 && det2[l] == 1)
        {
            fused[l]  = 1;

        }
        else
        {
            fused [l] = 0; 
        }
    }
}


int main()
{

    float time[N] = {0,1,2,3,4,5,6,7,8,9};

    double probability_sens1[N] = {0.2,0.9,0.65,0.78,0.72,0.67,0.45,0.56,0.34,0.67};
    double probability_sens2[N] = {0.4,0.6,0.8,0.92,0.45,0.58,0.2,0.27,0.89,0.88};

    int det1[N];
    int det2[N];
    int fused[N];

    compute_detection(probability_sens1, det1, N, 0.6);
    compute_detection(probability_sens2, det2, N, 0.7);
    
    printf("Sensor 1: \n");
    print_intervalls(det1, time, N);

    printf("Sensor 2: \n");
    print_intervalls(det2, time, N);

    compute_fusion(det1, det2, fused, N);
    printf("Fusion: \n");
    print_intervalls(fused, time, N);

    return 0; 


}