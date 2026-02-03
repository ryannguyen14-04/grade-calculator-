// These headers define some of the classes and functions we need
#include <iostream>
#include <string>
#include <sstream>
#include <limits>

// ONLY MAKE CHANGES WHERE THERE IS A TODO

// These using declarations let us refer to things more simply
// e.g. instead of "std::cin" we can just write "cin"
using std::cin, std::cout, std::endl;
using std::string, std::getline;

// These methods are defined below the main function

// print instructions for inputting grades
void print_instructions();

// pretty print a summary of the grades
void print_results(double exam_average,
                   double hw_average,
                   double lw_average,
                   double reading,
                   double engagement,
                   double weighted_total,
                   char final_letter_grade);

// YOU ARE NOT EXPECTED TO UNDERSTAND THIS ONE... YET
// extract the category and score from the line
// and store the values in the provided variables
// if line := "exam 95", then category := "exam" and score := 95
// if the line is invalid, then category := "ignore"
void get_category_and_score(const string& line,
                            string* category,
                            double* score);

int main() {
    print_instructions();

    // ONLY MAKE CHANGES WHERE THERE IS A TODO

    // TODO(student): declare and initialize variables that you want


    
    char final_letter_grade;
    string category;
    double a = 0;
    int examCount = 1; 

    double b = 0;
    int hwCount = 0; 

    double c = 0;
    int lwCount = 0; 


    double d = 0;
    int readingCount = 0; 


    double e = 0;
    int engagementCount = 0; 

    double x;
    double y;

    double f = 0;
    string line;
    double maxExamScore = 0;
    double exam_average = 0;

    // read one line from standard input (discards the ending newline character)
    getline(cin, line);
    // read lines until an empty line is read
    while (!line.empty()) {
        string category;
        double score = 0;
        get_category_and_score(line, &category, &score);

        // process the grade entry
        if (category == "exam") {
            a += score;
            ++examCount;
            if (score > maxExamScore) {
                maxExamScore = score;
            }
            // TODO(student): process exam score
        } else if (category == "final-exam") {
            // TODO(student): process final score
             f+= score;
        } else if (category == "hw") {
            b += score;
            ++hwCount;
            // TODO(student): process hw score
        } else if (category == "lw") {
             c += score;
            ++lwCount;
            // TODO(student): process lw score
        } else if (category == "reading") {
             d += score;
             d += 15;
            ++readingCount;
            // TODO(student): process reading score
        } else if (category == "engagement") {
             e += score;
            ++engagementCount;
            
            // TODO(student): process engagement score
        }
        else {
            cout << "ignored invalid input" << endl;
        }

        // get the next line from standard input
        getline(cin, line);

    }
    
            // TODO(student): process exam score
    // TODO(student): compute component averages
    if(examCount == 1){
        a = 0;
        } 
    if (hwCount == 0){
        b = 0;
        hwCount = 1;
        }
    if (lwCount == 0){
        c = 0; 
        lwCount = 1;
        }
    if (readingCount == 0){
        d = 0; 
        readingCount = 1;
        }
    if (engagementCount == 0){
        e = 0; 
        engagementCount = 1;
        }
    if (f > maxExamScore) {
        a = f;
        examCount = 1;
        exam_average = a / examCount;

    }else{
         exam_average = (a+f) / examCount;
    }

    double hw_average = b / hwCount;
    double lw_average = (c / lwCount) * 100;
    double reading = d / readingCount;
    double engagement = (e / engagementCount) + 15;

if (engagement == 15){
    engagement = 0;
}
if (reading > 100){
     x = reading - 100;
     reading = reading - x ;
}
if (engagement > 100){
     y = engagement - 100;
     engagement = engagement - y ;
}
    // TODO(student): compute weighted total of components
    double weighted_total = (exam_average * 0.4) + (hw_average * 0.4) + ( lw_average * 0.1) + (reading * 0.05) + (engagement * 0.05);

    // TODO(student): compute final letter grade
    
    if (weighted_total >= 90){
         final_letter_grade = 'A'; 
    }
    else if (weighted_total < 90 &&  weighted_total >= 80 ){
            final_letter_grade = 'B'; 
    }else if (weighted_total < 80 && weighted_total >= 70 ){
         final_letter_grade = 'C'; 
    }else if (weighted_total < 70 && weighted_total >= 60 ){
         final_letter_grade = 'D'; 
    }else if (weighted_total < 60  ){
         final_letter_grade = 'F'; 
    }

    print_results(
        exam_average, hw_average, lw_average, reading, engagement,
        weighted_total, final_letter_grade);
}

// These methods are already implemented for you
// You should not need to modify them

void print_instructions() {
    cout << "enter grades as <category> <score>" << endl;
    cout << "  <category> := exam | final-exam | hw | lw | reading | engagement" << endl;
    cout << "     <score> := numeric value" << endl;
    cout << "enter an empty line to end input" << endl;
}

void get_category_and_score(
    const string& line,
    string* category,
    double* score) {
    // turn the string into an input stream
    std::istringstream sin(line);

    // read the category (as string) and score (as double) from the stream
    sin >> *category;
    sin >> *score;

    if (sin.fail()) {
        // the stream is in a fail state (something went wrong)
        // clear the flags
        sin.clear();
        // clear the stream buffer (throw away whatever garbage is in there)
        sin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // signal that the line was invalid
        *category = "ignore";
    }
}

void print_results(
    double exam_average,
    double hw_average,
    double lw_average,
    double reading,
    double engagement,
    double weighted_total,
    char final_letter_grade) {
    cout << "summary:" << endl;
    cout << "      exam average: " << exam_average << endl;
    cout << "        hw average: " << hw_average << endl;
    cout << "        lw average: " << lw_average << endl;
    cout << "           reading: " << reading << endl;
    cout << "        engagement: " << engagement << endl;
    cout << "    ---------------" << endl;

    cout << "    weighted total: " << weighted_total << endl;

    cout << "final letter grade: " << final_letter_grade << endl;
}
