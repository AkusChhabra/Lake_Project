#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ArrSize 366
#define daysinyear 365
#define LakeNum 6
#define charnum 10


int month (int dayc, int *daycnum) {


   int monthc;


       if (dayc <= 31)  {             // Jan 31
           monthc = 1;
           *daycnum = dayc;
       }
       if (dayc > 31 && dayc <= 59) { // Feb 28
           monthc = 2;
           *daycnum = dayc -  31;
       }
       if (dayc > 59 && dayc <= 90) { // Mar 31
           monthc = 3;
           *daycnum = dayc -  59;
       }
       if (dayc > 90 && dayc <= 120) { // Apr 30
           monthc = 4;
           *daycnum = dayc -  90;
       }
       if (dayc > 120 && dayc <= 151) { // May 31
           monthc = 5;
           *daycnum = dayc -  120;
       }
       if (dayc > 151 && dayc <= 181) { // June 30
           monthc = 6;
           *daycnum = dayc -  151;
       }
       if (dayc > 181 && dayc <= 212) { // July 31
           monthc = 7;
           *daycnum = dayc -  181;
       }
       if (dayc > 212 && dayc <= 243) { // Aug 31
           monthc = 8;
           *daycnum = dayc -  212;
       }
       if (dayc > 243 && dayc <= 273) { // Sept 30
           monthc = 9;
           *daycnum = dayc -  243;
       }
       if (dayc > 273 && dayc <= 304) { // Oct 31
           monthc = 10;
           *daycnum = dayc -  273;
       }
       if (dayc > 304 && dayc <= 334) { // Nov 30
           monthc = 11;
           *daycnum = dayc -  304;
       }
       if (dayc > 334 && dayc <= 365) { // Dec 31
           monthc = 12;
           *daycnum = dayc -  334;
       }
   return monthc;
}


void lake (double lakename[], int dayarr[], int yeararr[], char lake[], int size) {


   int i, result1, result2, dayhpar, daycpar, yearh, yearc, coldnum, hotnum;
   double low, high;


   low = lakename[1];
   high = lakename[1];


           for (i = 2; i < size ;++i) {
               if (lakename[i] > high) {
                   high = lakename[i];
                   dayhpar = dayarr[i];
                   yearh = yeararr[i];
               }
               if (lakename[i] < low) {
                   low = lakename[i];
                   daycpar = dayarr[i];
                   yearc = yeararr[i];
               }
           }


   result1 = month(daycpar, &coldnum);
   result2 = month(dayhpar, &hotnum);


   printf("\nThe coldest temperature for lake %s was %.2lf ˚C on %d/%d/%d.", lake, low, result1, coldnum, yearc);
   printf("\n\nThe hottest temperature for lake %s was %.2lf ˚C on %d/%d/%d.\n\n", lake, high, result2, hotnum, yearh);
}


void minmax (double lakename[], double max, double min, int size, double *newmin, double *newmax) {


   int j;


       for (j = 2; j < size ;j++) {
           if (lakename[j] > max ) {
               max = lakename[j];
           }
           *newmax = max;
       }
       for (j = 2; j < size ;j++) {
           if (lakename[j] < min ) { 
               min = lakename[j];
           }
           *newmin = min;
       }
}


void temp (double lakename[], char lake[], double min, double max, int yeararr[], int dayarr[], int size) {


   int i, result1, result2, daycpar, dayhpar, coldnum, hotnum, yearc, yearh;


   for (i = 1; i < size ;++i) {
       if (lakename[i] == min) { // COLD
           yearc = yeararr[i];
           daycpar = dayarr[i];
           result1 = month(daycpar, &coldnum);
           printf("\n\nThe coldest temperature overall was for lake %s with a temperature of %.2lf ˚C on %d/%d/%d.", lake, min, result1, coldnum, yearc);
       }
       if (lakename[i] == max) { //HOT
           yearh = yeararr[i];
           dayhpar = dayarr[i];
           result2 = month(dayhpar, &hotnum);
           printf("\n\nThe hottest temperature overall was for lake %s with a temperature of %.2lf ˚C on %d/%d/%d.\n\n", lake, max, result2, hotnum, yearh);
       }
   }
}


double average (double lakename[], int min, int max, int size) {


   int i, count = 0;
   double sum = 0.0, avg = 0.0;


       for (i = min; i <= max ;++i) {
               sum += lakename[i];
               count++;
       }
   avg = sum/(double)count;


   return(avg);
}


double average2 (double lakename[], int min, int max, int min2, int max2, int size) {


   int i, count = 0.0;
   double sum = 0.0, avg = 0.0;


       for (i = min; i <= max ;++i) {
                   sum += lakename[i];
                   count++;
           }
       for (i = min2; i <= max2 ;++i) {
                   sum += lakename[i];
                   count++;
           }
   avg = sum/(double)count;


   return(avg) ;
}


void cycles1 (double lakename[], char lake[] , int size) {


   int i, count = 0.0;


       for (i = 0; i < size ;++i)
           if (lakename[i] > 20.0)
               count++;


   printf("\nThere are %d days where you can swim in lake %s.\n", count, lake);
}


void cycles2 (double lakename[], char lake[] , int size) {


   int i, count = 0.0;


   for (i = 0; i < size ;++i)
       if (lakename[i] < 0.0)
           count++;


   printf("\nThere are %d days where lake %s is frozen.\n", count, lake);
}


void question (int num) {
   printf("\n\n---------------------------------------------------------------------------------------------------------------------------------------------------");
   printf("\n\n========== QUESTION %d ==========\n", num);
}


void line (void) {
   printf("\n-------------------------------------------------------------------------");
}


int main(void) {


   int i, j;
   double sumS = 0.0, sumM = 0.0, sumH = 0.0, sumE = 0.0, sumO = 0.0, sumC = 0.0, avgS, avgS2, avgM, avgM2, avgH, avgH2, avgE, avgE2, avgO, avgO2, avgC, avgC2, low, high, avgLake, nlow, nhigh, avg2018;


   static char hold2[charnum];
   static char Llow[charnum];
   static char Lhigh[charnum];
   static char lakeT[charnum];
   static int year[ArrSize];
   static int day[ArrSize];
   static double superior[ArrSize];
   static double michigan[ArrSize];
   static double huron[ArrSize];
   static double erie[ArrSize];
   static double ontario[ArrSize];
   static double stclair[ArrSize];
   static int year2[ArrSize];
   static int day2[ArrSize];
   static double superior2[ArrSize];
   static double michigan2[ArrSize];
   static double huron2[ArrSize];
   static double erie2[ArrSize];
   static double ontario2[ArrSize];
   static double stclair2[ArrSize];


   question (1);  // QUESTION 1


   FILE *in;


       in = fopen("lake.txt","r");


           for (i = 1; i < ArrSize ;++i)
               fscanf(in, "%d %d %lf %lf %lf %lf %lf %lf", &year[i], &day[i], &superior[i], &michigan[i], &huron[i], &erie[i], &ontario[i], &stclair[i]);


   fclose(in);


       for (i = 1; i < ArrSize ;++i) {
           sumS += superior[i];
           sumM += michigan[i];
           sumH += huron[i];
           sumE += erie[i];
           sumO += ontario[i];
           sumC += stclair[i];
       }


   avgS = sumS/daysinyear;
   avgM = sumM/daysinyear;
   avgH = sumH/daysinyear;
   avgE = sumE/daysinyear;
   avgO = sumO/daysinyear;
   avgC = sumC/daysinyear;


   avgLake = (avgS + avgM + avgH + avgE + avgO + avgC)/6;


   printf("\n\nThe yearly temperature for lake Superior is %.2lf ˚C.\n", avgS);
   printf("\nThe yearly temperature for lake Michigan is %.2lf ˚C.\n", avgM);
   printf("\nThe yearly temperature for lake Huron is %.2lf ˚C.\n", avgH);
   printf("\nThe yearly temperature for lake Erie is %.2lf ˚C.\n", avgE);
   printf("\nThe yearly temperature for lake Ontario is %.2lf ˚C.\n", avgO);
   printf("\nThe yearly temperature for lake St. Clair is %.2lf ˚C.\n", avgC);
   printf("\nThe average of all the six lakes is %.2lf ˚C.\n", avgLake);


   question (2); // QUESTION 2


   char names[LakeNum][charnum] = {"Superior", "Michigan", "Huron", "Erie", "Ontario", "St. Clair"};
   double compare[LakeNum] = {avgS, avgM, avgH, avgE, avgO, avgC};


   low = compare[1];
   high = compare[1];


       for (i = 0; i < LakeNum ;++i) {         
           if (compare[i] > high) {
               high = compare[i];
               strcpy (Lhigh, &names[i - 1][charnum]);
           }
       }
       for (i = 0; i < LakeNum ;++i) {
           if (compare[i] < low) {
               low = compare[i];
               strcpy (Llow, &names[i - 1][charnum]);
           }
       }


   printf("\n\n\nThe lake with the lowest temperature is lake %s with an average temperature of %.2lf ˚C.", Llow, low);
   printf("\n\nThe lake with the highest temperature is lake %s with an average temperature of %.2lf ˚C.\n\n", Lhigh, high);


   printf("\n\nLakes that are less than the average:\n");


       for (i = 0; i < LakeNum ;++i) {
           if (compare[i] < avgLake) {
               strcpy (lakeT, &names[i - 1][charnum]);
               printf("\nLake: %s\t Temperature: %.2lf", lakeT, compare[i]);
           }
       }


   printf("\n\n\nLakes that are above the the average:\n");


       for (i = 0; i < LakeNum ;++i) {
           if (compare[i] > avgLake) {
               strcpy (lakeT, &names[i - 1][charnum]);
               printf("\nLake: %s\t Temperature: %.2lf", lakeT, compare[i]);
           }
       }


   question (3); // QUESTION 3


   char a[charnum], b[charnum], c[charnum], d[charnum], e[charnum], f[charnum];


   strcpy(a, "Superior");
   strcpy(b, "Michigan");
   strcpy(c, "Huron");
   strcpy(d, "Erie");
   strcpy(e, "Ontario");
   strcpy(f, "St. Clair");


   lake(superior, day, year, a, ArrSize);
   lake(michigan, day, year, b, ArrSize);
   lake(huron, day, year, c, ArrSize);
   lake(erie, day, year, d, ArrSize);
   lake(ontario, day, year, e, ArrSize);
   lake(stclair, day, year, f, ArrSize);


   question (4); // QUESTION 4


   low = superior[1];
   high = superior[1];


   minmax(superior, high, low, ArrSize, &nlow, &nhigh);
   low = nlow;
   high = nhigh;


   minmax(michigan, high, low, ArrSize, &nlow, &nhigh);
   low = nlow;
   high = nhigh;


   minmax(huron, high, low, ArrSize, &nlow, &nhigh);
   low = nlow;
   high = nhigh;


   minmax(erie, high, low, ArrSize, &nlow, &nhigh);
   low = nlow;
   high = nhigh;


   minmax(ontario, high, low, ArrSize, &nlow, &nhigh);
   low = nlow;
   high = nhigh;


   minmax(stclair, high, low, ArrSize, &nlow, &nhigh);


   temp(superior, a, nlow, nhigh, year, day, ArrSize);
   temp(michigan, b, nlow, nhigh, year, day, ArrSize);
   temp(huron, c, nlow, nhigh, year, day, ArrSize);
   temp(erie, d, nlow, nhigh, year, day, ArrSize);
   temp(ontario, e, nlow, nhigh, year, day, ArrSize);
   temp(stclair, f, nlow, nhigh, year, day, ArrSize);


   question (5); // QUESTION 5


   double avg1 = 0.0, avg2 = 0.0, avg3 = 0.0, avg4 = 0.0, avg5 = 0.0, avg6 = 0.0, hold;


   avg1 = average(superior, 172, 265, ArrSize);
   avg2 = average(michigan, 172, 265, ArrSize);
   avg3 = average(huron, 172, 265, ArrSize);
   avg4 = average(erie, 172, 265, ArrSize);
   avg5 = average(ontario, 172, 265, ArrSize);
   avg6 = average(stclair, 172, 265, ArrSize);


   double arravg1[LakeNum] = {avg1, avg2, avg3, avg4, avg5, avg6};


           for (i = 0; i < LakeNum - 1 ;++i)  {     
               for (j = 0; j < LakeNum - i - 1 ;++j) {
                       if (arravg1[j] < arravg1[j + 1]) {
                           hold = arravg1[j];
                           arravg1[j] = arravg1[j + 1];
                           arravg1[j + 1] = hold;
                           strcpy(&hold2, &names[j]);
                           strcpy(&names[j], &names[j + 1]);
                           strcpy(&names[j + 1], &hold2);
                       }
               }
           }


   for (i = 0; i < LakeNum; ++i)
       printf("\n\n%s at %.2lf ˚C.", names[i], arravg1[i]);


   printf("\n\n\nThe order from warmest to coldest is the same as the yearly average calculated in question 2.\n");
  
   question (6); // QUESTION 6


   avg1 = average2(superior, 1, 79, 355, 365, ArrSize);
   avg2 = average2(michigan, 1, 79, 355, 365, ArrSize);
   avg3 = average2(huron, 1, 79, 355, 365, ArrSize);
   avg4 = average2(erie, 1, 79, 355, 365, ArrSize);
   avg5 = average2(ontario, 1, 79, 355, 365, ArrSize);
   avg6 = average2(stclair, 1, 79, 355, 365, ArrSize);


   char names2[LakeNum][charnum] = {"Superior", "Michigan", "Huron", "Erie", "Ontario", "St. Clair"};
   double arravg2[LakeNum] = {avg1, avg2, avg3, avg4, avg5, avg6};


           for (i = 0; i < LakeNum - 1 ;++i)  {     
               for (j = 0; j < LakeNum - i - 1 ;++j) {
                       if (arravg2[j] < arravg2[j + 1]) {
                           hold = arravg2[j];
                           arravg2[j] = arravg2[j + 1];
                           arravg2[j + 1] = hold;
                           strcpy(&hold2, &names2[j]);
                           strcpy(&names2[j], &names2[j + 1]);
                           strcpy(&names2[j + 1], &hold2);
                       }
               }
           }


       for (i = 0; i < LakeNum; ++i)
           printf("\n\n%s at %.3lf ˚C.", names2[i], arravg2[i]);


   printf("\n\n\nThe order from warmest to coldest is not the same as the yearly average calculated in question 2.\n");


   question (7); // QUESTION 7


   cycles1(superior, a, ArrSize);
   cycles1(michigan, b, ArrSize);
   cycles1(huron, c, ArrSize);
   cycles1(erie, d, ArrSize);
   cycles1(ontario, e, ArrSize);
   cycles1(stclair, f, ArrSize);


   question (8); // QUESTION 8


   cycles2(superior, a, ArrSize);
   cycles2(michigan, b, ArrSize);
   cycles2(huron, c, ArrSize);
   cycles2(erie, d, ArrSize);
   cycles2(ontario, e, ArrSize);
   cycles2(stclair, f, ArrSize);


   question (9); // QUESTION 9


   sumS = 0.0, sumM = 0.0, sumH = 0.0, sumE = 0.0, sumO = 0.0, sumC = 0.0;


   FILE *in2;


       in2 = fopen("lake2.txt","r");


           for (i = 1; i < ArrSize ;++i)
               fscanf(in2, "%d %d %lf %lf %lf %lf %lf %lf", &year2[i], &day2[i], &superior2[i], &michigan2[i], &huron2[i], &erie2[i], &ontario2[i], &stclair2[i]);


       fclose(in2);


           for (i = 1; i < ArrSize ;++i) {
                   sumS += superior2[i];
                   sumM += michigan2[i];
                   sumH += huron2[i];
                   sumE += erie2[i];
                   sumO += ontario2[i];
                   sumC += stclair2[i];
               }


       avgS2 = sumS/daysinyear;
       avgM2 = sumM/daysinyear;
       avgH2 = sumH/daysinyear;
       avgE2 = sumE/daysinyear;
       avgO2 = sumO/daysinyear;
       avgC2 = sumC/daysinyear;


       avg2018 = (avgS2 + avgM2 + avgH2 + avgE2 + avgO2 + avgC2)/6;


       line ();
       printf("\n|\tLake Name\t|\t%d\t\t|\t%d\t\t|",year2[1],year[1]);
       line ();
       printf("\n|\t%s\t|\t%.2lf ˚C\t\t|\t%.2lf ˚C\t\t|", a, avgS2, avgS);
       printf("\n|\t%s\t|\t%.2lf ˚C\t\t|\t%.2lf ˚C\t\t|", b, avgM2, avgM);
       printf("\n|\t%s\t\t|\t%.2lf ˚C\t\t|\t%.2lf ˚C\t\t|", c, avgH2, avgH);
       printf("\n|\t%s\t\t|\t%.2lf ˚C\t|\t%.2lf ˚C\t|", d, avgE2, avgE);
       printf("\n|\t%s\t\t|\t%.2lf ˚C\t|\t%.2lf ˚C\t\t|", e, avgO2, avgO);
       printf("\n|\t%s\t|\t%.2lf ˚C\t|\t%.2lf ˚C\t|", f, avgC2, avgC);
       line ();
       printf("\n|\t%s\t|\t%.2lf ˚C\t\t|\t%.2lf ˚C\t\t|", "Lake Average", avg2018, avgLake);
       line ();
   return(0);
}
