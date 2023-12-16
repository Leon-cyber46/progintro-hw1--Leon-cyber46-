#include <stdio.h>
#include <stdlib.h> 
#include <math.h> // λόγω χρήσης της fabs //

#define LIMIT 1e-6
#define K 1000

int main(int argc, char *argv[]) {   // ελέγχει αν έχουμε δώσει αρκετά ορίσματα // 
if (argc != 8) { 
    printf("Fault\n");
    return 1;
}

double c = atof(argv[1]);   // μετατρέπει το ορίσματα σε double //
double x1 = atof(argv[2]);
double x2 = atof(argv[3]);
double x3 = atof(argv[4]);
double x4 = atof(argv[5]);
double x5 = atof(argv[6]);
double f = atof(argv[7]);

int j = 0;   // μετρητής επαναλήψεων //
double temp;   // προσέγγιση της ρίζας //

double denominator = x1 + (2 * x2 * f) + (3 * x3 * f * f) + (4 * x4 * f * f * f) + (5 * x5 * f * f * f * f); // διαιρέτης F'(x) //

if (x1 + (2 * x2 * f) + (3 * x3 * f * f) + (4 * x4 * f * f * f) + (5 * x5 * f * f * f * f) == 0){  // ελέγχει αν η ρίζα που δώσαμε είναι ακρότατο - F'(x) = 0 //
     printf("nan\n");
     return -1;
}

temp = f - (((f * x1) + ((f * f) * x2) + ((f * f * f) * x3) + ((f * f * f * f) * x4) + ((f * f * f * f * f) * x5)+c)/(x1 + (2 * x2 * f) + (3 * x3 * f * f) + (4 * x4 * f * f * f) + (5 * x5 * f * f * f * f)));  // πρώτη προσέγγιση της ρίζας-πρώτο x(n+1)=x(n)-f(x)/f'(x) //

while((fabs(temp - f) > LIMIT) && (j < K)){   // χρήση της fabs για την απόλυτη τιμή της αφαίρεσης και την εύρεση της απόκλισης μεταξύ των διαδοχικών προσεγγίσεων-ελέγχει επίσης αν έχουμε 1000 επαναλήψεις //
    f = temp; // χρησιμεύει στην σύγκριση της καινούργιας προσέγγισης με την προηγούμενη //
    denominator = x1 + (2 * x2 * temp) + (3 * x3 * temp * temp) + (4 * x4 * temp * temp * temp) + (5 * x5 * temp * temp * temp * temp); // διαιρέτης F'(x) για την κάθε προσέγγιση //
    if(denominator == 0){ // ελέγχει αν η εκάστοτε προσέγγιση μηδενίζει το F'(x) //
         printf("nan\n"); 
         return -1;
    }
    temp = temp - (((temp * x1) + ((temp * temp) * x2) + ((temp * temp * temp) * x3) + ((temp * temp * temp * temp) * x4) + ((temp * temp * temp * temp * temp) * x5)+ c)/(denominator)); // x(n+1)=x(n)-F(x)/F'(x) //
    j += 1; // αυξάνει με κάθε προσέγγιση //
}
    
if (j < K) { // αν δεν έγιναν 1000 επαναλήψεις τυπώνει την ρίζα //
    printf( "%.2lf\n", temp);
} else {
    printf("incomplete\n"); // αλλιώς έγιναν 1000 επαναλήψεις και τυπώνει incomplete //
}

return 0;
}


