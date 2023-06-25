#include "homework_run_test.h"

#define MAX 5
// number_of_attendances 

int is_error(float score[MAX], int late[MAX], int number_of_exercises, int number_of_attendances){

    if ( number_of_exercises < 1 || number_of_exercises > 5)
        return 1;

    if ( number_of_attendances  < 0 || number_of_attendances > 15)
        return 1;

    int index = 0;
    for( index = 0; index < number_of_exercises; index += 1){
        if (score[index] < 0 || score[index] > 10)
            return 1;

        switch (late[index])
        {
        case 0:
        case 1:
            break;
        default:
            return 1;
        }
    }

    return 0;
}

float calculate_sum(float score[], int late[], int number_of_exercises){
    int count = 0, index = 0;
    float result = 0;
    for( index = 0; index < number_of_exercises; index += 1){
        
        if (late[index] == 1){
            count += 1;
            if (count < 3){
                result += score[index] * 90 / 100;
                continue;
            }
            if (count == 3)
            {
                result += score[index] * 70 / 100;
                continue;
            }

            if (count > 3)
                return result;
        }
        else{
            result += score[index];
        }
    }
    return result;
}


float round_score(float score){
    int temp_score = score;
    float temp = score - temp_score;
    if (temp == 0.f)
        return score;
    
    if (temp < 0.25f)
        return temp_score;

    if (temp < 0.75f)
        return temp_score + 0.5f;
    // printf(" %f ", temp);
    
    return temp_score + 1.f;
}

float calculate_practice_form2_score(int number_of_exercises, float score[MAX], int late[MAX], int number_of_attendances){

    float result = -1;

    if (is_error(score, late, number_of_exercises, number_of_attendances))
        return result;

    result = calculate_sum(score, late, number_of_exercises) / number_of_exercises;

    if (result > 5 && number_of_attendances < 10){
        result = result * 90 / 100;
    }
    result = round_score(result);
    return result;
}

int main(void){

    homework_run_test(1, calculate_practice_form2_score(0, (float[]){0}, (int[]){0}, 0), -1);
    homework_run_test(2, calculate_practice_form2_score(6, (float[]){0}, (int[]){0}, 0), -1);

    homework_run_test(3, calculate_practice_form2_score(2, (float[]){0,-1}, (int[]){0,0}, 0), -1);
    homework_run_test(4, calculate_practice_form2_score(2, (float[]){0,10.1}, (int[]){0,0}, 0), -1);

    homework_run_test(5, calculate_practice_form2_score(2, (float[]){0,0}, (int[]){0,-1}, 0), -1);
    homework_run_test(6, calculate_practice_form2_score(2, (float[]){0,0}, (int[]){0,2}, 0), -1);

    homework_run_test(7, calculate_practice_form2_score(1, (float[]){0}, (int[]){0}, -1), -1);
    homework_run_test(8, calculate_practice_form2_score(1, (float[]){0}, (int[]){0}, 16), -1);

    homework_run_test(9, calculate_practice_form2_score(5, (float[]){2,2,2,2,2}, (int[]){0,0,0,0,0}, 15), 2);

    homework_run_test(10, calculate_practice_form2_score(5, (float[]){0.24,0.24,0.24,0.24,0.24}, (int[]){0,0,0,0,0}, 15), 0.f);
    homework_run_test(11, calculate_practice_form2_score(5, (float[]){0.25,0.25,0.25,0.25,0.25}, (int[]){0,0,0,0,0}, 15), 0.5f);
    homework_run_test(12, calculate_practice_form2_score(5, (float[]){0.74,0.75,0.75,0.75,0.75}, (int[]){0,0,0,0,0}, 15), 0.5f);
    homework_run_test(13, calculate_practice_form2_score(5, (float[]){0.75,0.75,0.75,0.75,0.75}, (int[]){0,0,0,0,0}, 15), 1.f);

    homework_run_test(14, calculate_practice_form2_score(5, (float[]){0.75,0.75,0.75,0.75,0.75}, (int[]){1,0,0,0,0}, 15), 0.5f);
    homework_run_test(15, calculate_practice_form2_score(5, (float[]){0.28,0.25,0.25,0.25,0.25}, (int[]){1,0,0,0,0}, 15), 0.5f);
    homework_run_test(16, calculate_practice_form2_score(5, (float[]){0.28,0.24,0.25,0.25,0.25}, (int[]){1,1,0,0,0}, 15), 0.f);


    
    homework_run_test(17, calculate_practice_form2_score(4, (float[]){6, 7, 8.5, 9}, (int[]){0, 0, 0, 0}, 13), 7.5);

    homework_run_test(18, calculate_practice_form2_score(2, (float[]){5, -6}, (int[]){0, 0}, 11), -1);  
    homework_run_test(19, calculate_practice_form2_score(3, (float[]){8.5, 7, 9.5}, (int[]){0, 1, 0}, 9), 7.5);

    homework_run_test(20, calculate_practice_form2_score(5, (float[]){9, 8.5, 9, 8, 7.5}, (int[]){1, 1, 1, 1, 1}, 8), 4.5);

    homework_run_test(21, calculate_practice_form2_score(4, (float[]){8, 7.5, 8, 9}, (int[]){1, 1, 1, 0}, 12), 7);

    homework_run_test(22, calculate_practice_form2_score(4, (float[]){9, -8, 20, 7}, (int[]){0, 3, 0, 1}, 100), -1); 

    return 0;
}