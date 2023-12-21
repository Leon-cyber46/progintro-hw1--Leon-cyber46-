#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define LIMIT 1e15 // ανώτατο όριο 

long long int reversed( long long int i){    // υπολογίζει το κάτοπτρο ενος αριθμού i
    int temp;
    int reverse = 0;

    while(i > 0){
        temp = i % 10;     // παίρνει το τελευταίο ψηφίο του τετραγώνου 
        reverse = reverse * 10 + temp;    // χτίζει το κάτοπτρο 
        i = i/10; 
    }

return reverse;   // επιστρέφει το κάτοπτρο 
}


int palindrome(long long int i){
    long long int result = 0;
    long long int first = i;
    int temp;

    while (i > 0) {
        temp = i % 10;  // παίρνει το τελευταίο ψηφίο του i
        result = result * 10 + temp; // χτίζει τον παλινδρομικό αριθμό του i 
        i /= 10;
    }

    return (first!=result);  // επιστρέφει την λογική τιμή του expression 
}


int main(int argc, char *argv[]){

if(argc != 3){
    printf("Fault\n");          // ελέγχει αν δώσαμε σωστές παραμέτρους 
    return 1;
}

long long int low = atoll(argv[1]);   // μετατροπή σε long long int λόγω μεγάλων αριθμών 
long long int high = atoll(argv[2]);

long long int mirror;
long long int i, j, k;
long long int sum = 0;
long long int counter = 0;
long long int mirrorcounter = 0;


if(high > LIMIT || high < 0 || low < 0 || (high <= low)){
    printf("Fault\n");          // ελέγχει για εισόδους εκτός ορίων 
    return 1;
}
if(high <=10){
    printf("The sum is %d\n", 0);  // όλοι οι μονοψήφιοι είναι παλινδρομικοί - δεν μας ενδιαφέρουν 
}
if(low % 2 == 0){   // θέλουμε να εξετάζουμε μόνο περιττούς (όλοι οι άρτιοι αποτελούνται από γινόμενο άρτιων)
    low += 1;
}
for(i=low; i<=high; i=i+2){ // βήμα 2 γιατί θα εξετάζουμε μόνο περιττούς 

    if(sqrt(i)-ceil(sqrt(i))==0){ // ελέγχει αν ο εκάτσοτε αριθμός έχει ακέραια ρίζα 
        counter = 0;  // μετρητής για το αν είναι πρώτος ή όχι 
        long long int root = (int)sqrt(i); 

        for(k=1; k<=root; k=k+2){   // ελέγχει αν είναι πρώτος η ρίζα του i 
            if(root % k == 0){
                counter += 1;
                
            }
        }
        if(counter == 2){  // αν είναι πρώτος η ρίζα του i τότε υπολογίζει το κάτοπτρό του 
            mirror = reversed(i); // υπολογισμός κατοπτρικού αριθμού 
            
            mirrorcounter = 0;
            if(sqrt(mirror)-ceil(sqrt(mirror)) == 0){  // υπολογίζει αν η ρίζα του κατοπτρικού αριθμού είναι ακέραιος 
                 long long int mirrorroot = (int)sqrt(mirror);  
                 for(j=1; j<=mirrorroot; j=j+1){  // αν είναι τοτε ελέγχει αν είναι και πρώτος 
                    if(mirrorroot % j == 0){
                        mirrorcounter += 1;
                    }
                 }            
            }
            if(mirrorcounter == 2){  // αν είναι πρώτος και η ρίζα του κατοπτρικού αριθμού ελέγχει αν είναι παλινδρομικός το i
                if(palindrome(i)){
                    sum += i; // αν πληροί όλες τις προυποθέσεις τότε προσθέτει τον αριθμό που εξετάζεται 
                }
            } 

        }
    
    }


}
printf("%lld\n", sum); // τύπωσε το αποτέλεσμα 

return 0;
}