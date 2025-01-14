//structure for hospital

struct hospital {
 char name[50];
 char city[50];
 int beds;
 float price;
 float rating;
 int reviews;
};

//structure for patient

struct patient{
char name[50];
int age;
};


//function to print hospital data

void printhospital(struct hospital hosp) {
printf("hospital name: %s\n", hosp.name);
printf("city: %s\n", hosp.city);
printf("total beds: %d\n", hosp.beds);
printf("price per bed: $%.2f\n, hosp.price");
printf("rating: %.1f\n", hosp.rating);
printf("reviews: %d\n", hosp.reviews);
printf("\n");
}

//function to print all patient data
void printpatient(struct patient patient){
printf("patient name: %s\n", patient.name);
printf("age: %d\n", patient.age);
printf("\n");
}

//function to sort hospitals bt beds price
void sortbyprice(struct hospital hospitals[], int n) {
//implement sorting logic (bubble sorting)

for(int i = 0; i < n - 1; i++){
    for (int j = 0; j < n - i - 1; j++){
        if (hospitals[j].price > hospitals[j + 1].price){
            struct hospital temp = hospitals[j];
            hospitals[j] = hospitals[j + 1];
            hospitals[j + 1] = temp;
        }
    }
}

}


// function to sort hospitals by available beds

void sortbybeds(struct hospital hospitals[], int n) {
//implementing bubble sorting

for (int i = 0; i < n-1; i++){
    for (int j = 0; j < n - i - 1; j++){
        if (hospitals[j].beds , hospitals[j + 1].beds){
            struct hospital temp = hospitals[j];
            hospitals[j] = hospitals[j + 1];
            hospitals[j + 1]= temp;
        }
    }
}
}

//function to sort hospitals by name
void sortbyname(struct hospital hospitals[], int n) {

 for (int i = 0; i < n - 1; i++){
    for (int j = 0; j < n -i - 1; j++){
        if (strcmp(hospitals[j].name, hospitals[j + 1].name) > 0){

            struct hospital temp = hospitals[j];
            hospitals[j] = hospitals[j + 1];
            hospitals[j + 1] = temp;
        }
    }
 }

}


//function to sort hospitals by rating and reviews

void sortbyrating(struct hospital hospitals[], int n) {
for (int i = 0; i < n - 1; i ++){

    for (int j = 0; j < n - i - 1; j++){
        if (hospitals[j].rating * hospitals[j].reviews < hospitals[j + 1].rating * hospitals[j + 1].reviews) {
            struct hospital temp = hospitals[j];
            hospitals[j] = hospitals[j +1];
            hospitals[j + 1] = temp;
        }
    }
}

}

//function to print hospital in specific citys
void printhospitasincity(struct hospital hospitals[]) {
char city[50];
int hospitalsfound = 0;

printf("enter city name (x, y or z):  ");
scanf("%s", city);

printf("hospitals in %s:\n", city);

for(int i = 0; i < 5; i ++){
    if (strcasecmp(hospitals[i].city, city) == 0) {
        printf("hospital name: %s\n", hospitals[i].name);
        printf("city: %s\n", hospitals[i].city);
        printf("total beds: %d\n", hospitals[i].beds);
        printf("price per bed: $%.2f\n", hospitals[i].price);
        printf("rating: %.1f\n", hospitals[i].rating);
        printf("reviews: %d\n", hospitals[i].reviews);
        printf("\n");
        hospitalsfound++;

    }
}



if (hospitalsfound == 0) {
    printf("no hospitals found in %s\n", city);
}
}


int main(){
// sample hospital data
struct hospital hospitals[5] = {

   {"hospital a", "x", 100, 250.0, 4.5, 100},
   {"hospital b", "y", 150, 200.0, 4.2, 80},
   {"hospital c", "x", 200,180.0, 4.0, 120},
   {"hospital d", "z", 80, 300.0, 4.8, 90},
   {"hospital e", "y", 120, 220.0, 4.6, 110},
};
//sample patient data
struct patient patients[5][3] = {
{{"Amar", 35}, {"Manish", 45}, {"Atul", 28}},
        {{"Elvish", 62}, {"Debolina", 18}, {"Shruti", 55}},
        {{"Zafar", 50}, {"Rahul", 30}, {"Priya", 40}},
        {{"Amir", 22}, {"Asif", 38}, {"Prince", 60}},
        {{"Aditya", 28}, {"Aman", 48}, {"Sahil", 33}}
};
int n = 5;
int choice;
char city[50];

do{
    printf("\n\n\n ******welcome to my hospital managment system******\n\n");
    printf("\n\n\n*****here is the menu:*****\n\n");
    printf("1. printing hospital data\n");
    printf("2.printing patients data\n");
    printf("3.sorting hospitals by beds prices\n");
    printf("4.sorting hospitals by available beds\n");
    printf("5.sorting hospitals by name\n");
    printf("6.sorting hospitals by rating and reviews\n");
    printf("7.print hospitals in specific city\n");
    printf("8. exit\n\n");
    printf("enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
case 1:
    printf("\n printing hospital data:\n\n");
    for(int i = 0; i < n; i ++) {
        printhospital(hospitals[i]);
    }
    break;
case 2:
    printf("printing patients data:\n\n");
    for(int i = 0; i < n; i++){
        printf("hospitals: %s\n", hospitals[i].name);
        for(int j = 0; j < 3; j++) {
            printpatient(patients[i][j]);
        }
    }
    break;
case 3:
    printf("sorting hospitals by bed price : \n");
    sortbybeds(hospitals, n);
    for(int i = 0; i < n; i++) {
        printhospital(hospitals[i]);
    }
    break;
case 4:
    printf("sorting hospitals by available beds: \n");
    sortbybeds(hospitals, n);
    for (int i = 0; i < n; i++) {
        printhospital(hospitals[i]);

    }
    break;
case 6:
    printf("sorting hospitals by rating and reviews: \n");
    sortbyrating(hospitals, n);
    for (int i = 0; i < n; i++){
        printhospital(hospitals[i]);
    }
    break;
case 7:
    printhospitasincity(hospitals);
    break;
case 8:
    printf("exiting the program.\n");
    break;
default:
    printf("invalid choice. please enter a vaild option.\n");
    }
}
while (choice !=8);
return 0;


}


