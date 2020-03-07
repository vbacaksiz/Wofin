#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int writingFileForUse(int numOfWords,FILE*file1,FILE*file2)
{
    file1=fopen("dictionary.txt","r");
    file2=fopen("copyOfDictionary2.txt","w");
    char line[128];
    while(fgets(line,sizeof line,file1)!=NULL)
    {
        fputs(line,file2);
        numOfWords++;
    }
    fclose(file2);
    fclose(file1);

    return numOfWords;
}

char selectRandomWord(char*randomWord,int random,FILE*file2)
{
    file2=fopen("copyOfDictionary2.txt","r");
    int i=0;
    char line[128];
    while(fgets(line,sizeof line,file2)!=NULL)
    {
        if(i==random)
        {
            strcpy(randomWord,line);
        }
        i++;
    }
    fclose(file2);
    return *randomWord;
}



int findingNumOfLettersSecretWord(char*secretWord,int numOfLettersSecretWord)
{
    while(secretWord[numOfLettersSecretWord]!= '\0')
    {
            numOfLettersSecretWord++;
    }
    return numOfLettersSecretWord;
}

int findingNumOfLettersRandomWord(char*randomWord,int numOfLettersRandomWord)
{
    while(randomWord[numOfLettersRandomWord]!= '\0')
    {
        numOfLettersRandomWord++;
    }
    numOfLettersRandomWord--;
    return numOfLettersRandomWord;
}

char* copying(char*wordToCopy,char*copy)
{
    int p=0;
    while(wordToCopy[p]!='\0')
    {
        copy[p]=wordToCopy[p];
        p++;
    }
    return copy;
}

int findingNormalNumOfSameLetters(int numOfLettersSecretWord,char*secretWord,int numOfLettersRandomWord,char*copyOfRandomWord,int normalNumOfSameLetters)
{
    for(int k=0;k<numOfLettersSecretWord;k++){
        for(int l=0;l<numOfLettersRandomWord;l++){
            if(secretWord[k]==copyOfRandomWord[l]){
                    secretWord[k]=0;
                    copyOfRandomWord[l]=1;
                normalNumOfSameLetters++;
                break;
            }
        }
    }
    return normalNumOfSameLetters;
}

int findingCartesianNumOfSameLetters(int numOfLettersSecretWord,char*secretWord,int numOfLettersRandomWord,char*copyOfRandomWord,int cartesianNumOfSameLetters)
{
    for(int k=0;k<numOfLettersSecretWord;k++){
        for(int l=0;l<numOfLettersRandomWord;l++){
            if(secretWord[k]==copyOfRandomWord[l]){
                cartesianNumOfSameLetters++;
            }
        }
    }
    return cartesianNumOfSameLetters;
}

void updatingFile(int random,char*copyOfRandomWord,char*randomWord,int numOfLettersRandomWord,int normalNumOfSameLetters,FILE*file2,FILE*file3)
{
    int i=0;
    file3=fopen("copyOfDictionary.txt","w");
    file2=fopen("copyOfDictionary2.txt","r");
    int numOfLettersWord=0;
    int accuracyValue=0;
    char line[128];
    char word[15];
    while(fgets(line,sizeof line,file2)!=NULL){
            i++;
            if(i-1==random){

                    continue;
            }

            strcpy(word,line);
            copying(randomWord,copyOfRandomWord);

            while(word[numOfLettersWord]!= '\0'){

                numOfLettersWord++;

            }
            numOfLettersWord--;

            for(int k=0;k<numOfLettersWord;k++){
                for(int l=0;l<numOfLettersRandomWord;l++){
                    if(word[k]==copyOfRandomWord[l]){
                        accuracyValue++;
                        word[k]=0;
                        copyOfRandomWord[l]=1;
                        break;
                    }
                }
            }

            if(normalNumOfSameLetters==accuracyValue){
                fputs(line,file3);
            }
            accuracyValue=0;
            numOfLettersWord=0;
       }
       fclose(file3);
       fclose(file2);
}

int findingNumOfWord(int numOfWords,FILE*file3)
{
    file3=fopen("copyOfDictionary.txt","r");
    numOfWords=0;
    char line[128];
    while(fgets(line,sizeof line,file3)!=NULL){
        fputs(line,file3);
        numOfWords++;
    }
    fclose(file3);
    return numOfWords;
}

void updatingFileForUse(FILE*file2,FILE*file3)
{
    file2=fopen("copyOfDictionary2.txt","w");
    file3=fopen("copyOfDictionary.txt","r");
    char line[128];
    while(fgets(line,sizeof line,file3)!=NULL)
    {
        fputs(line,file2);
    }
    fclose(file2);
    fclose(file3);
}

int controlOfAccuracy(char*copyOfSecretWord,int numOfLettersSecretWord,char*copyOfRandomWord,int accuracyValue,int numOfLettersRandomWord)
{
    if(numOfLettersSecretWord==numOfLettersRandomWord){

    for(int k=0;k<numOfLettersSecretWord;k++)
    {
        if(copyOfSecretWord[k]==copyOfRandomWord[k])
        {
            accuracyValue++;
        }

    }
    return accuracyValue;
    }
    else{
        accuracyValue=0;
        return accuracyValue;
    }
}
int controlOfCartesianAccuracy(int numOfLettersSecretWord,int numOfLettersSelectedWord,char*copyOfSelectedWord,char *copyOfEnteredWord,int cartesianAccuracyValue)
{
    for(int k=0;k<numOfLettersSelectedWord;k++){
        for(int l=0;l<numOfLettersSecretWord;l++){
            if(copyOfSelectedWord[k]==copyOfEnteredWord[l]){
                cartesianAccuracyValue++;
            }
        }
    }
    return cartesianAccuracyValue;
}

void addToDictionary(char* secretWord,FILE*file1){
    file1=fopen("dictionary.txt","a");
    fprintf(file1,"\n");
    fputs(secretWord,file1);
    fclose(file1);


}

void controlOfLetters(FILE*file2,char*alphabet,int d){
    char line[128];
    char word[20];
    int a=0;
    int numOfLettersWord=0;
    file2=fopen("copyOfDictionary2.txt","r");
    while(a!=1){
        while(fgets(line,sizeof line,file2)!= NULL){

            strcpy(word,line);
            while(word[numOfLettersWord]!= '\0' ){
                numOfLettersWord++;
            }
            numOfLettersWord--;

            for(int p=0;p<numOfLettersWord;p++){
                if(a!=1){
                    if(alphabet[d]==word[p]){
                        a=1;
                        printf("1  ");
                        break;
                    }
                }
            }
        }
        if(a!=1){
            a=1;
            printf("0  ");
            break;
        }
    }
    if(alphabet[d+1]!='\0'){
            d++;
            controlOfLetters(file2,alphabet,d);

    }
}

void writingLetters(char*alphabet,FILE*file2){
    int k=0;
    while(alphabet[k]!= '\0' ){
            printf("%c  ",alphabet[k]);
            k++;
    }
    printf("\n\n");
    int d=0;
    controlOfLetters(file2,alphabet,d);

}

char computerFindsTheWord(int numOfWords,char*secretWord,FILE*file1,FILE*file2,FILE*file3,int numOfSteps,char*alphabet)
{
    int random=rand()%numOfWords;

    char randomWord[20];
    char copyOfSecretWord[20]={""};
    selectRandomWord(randomWord,random,file2);
    printf("\nRANDOM WORD     =%s\n",randomWord);

    int numOfLettersSecretWord=0;

    numOfLettersSecretWord=findingNumOfLettersSecretWord(secretWord,numOfLettersSecretWord);

    int numOfLettersRandomWord=0;

    numOfLettersRandomWord=findingNumOfLettersRandomWord(randomWord,numOfLettersRandomWord);

    char copyOfRandomWord[20]={""};

    copying(randomWord,copyOfRandomWord);
    copying(secretWord,copyOfSecretWord);

    int normalNumOfSameLetters=0;

    normalNumOfSameLetters=findingNormalNumOfSameLetters(numOfLettersSecretWord,copyOfSecretWord,numOfLettersRandomWord,copyOfRandomWord,normalNumOfSameLetters);

    int cartesianNumOfSameLetters=0;



    printf("NORMAL ACCURACY     =%d\n",normalNumOfSameLetters);

    copying(randomWord,copyOfRandomWord);
    copying(secretWord,copyOfSecretWord);
    cartesianNumOfSameLetters=findingCartesianNumOfSameLetters(numOfLettersSecretWord,copyOfSecretWord,numOfLettersRandomWord,copyOfRandomWord,cartesianNumOfSameLetters);
    printf("CARTESIAN ACCURACY  =%d\n",cartesianNumOfSameLetters);
    updatingFile(random,copyOfRandomWord,randomWord,numOfLettersRandomWord,normalNumOfSameLetters,file2,file3);

    numOfWords=findingNumOfWord(numOfWords,file3);

    printf("NUMBER OF REMAINING WORDS =%d\n",numOfWords);
    printf("REMAINING LETTERS\n");
    writingLetters(alphabet,file2);
    printf("\n");

    updatingFileForUse(file2,file3);
    int accuracyValue=0;
    accuracyValue=controlOfAccuracy(copyOfSecretWord,numOfLettersSecretWord,randomWord,accuracyValue,numOfLettersRandomWord);
    if(accuracyValue==numOfLettersSecretWord){
       printf("CONGRATULATIONS! COMPUTER FOUND THE WORD IN %d. STEPS =%s\n",numOfSteps,randomWord);
       return randomWord;
    }
    else if(numOfWords==0)
    {

        random=0;
        selectRandomWord(randomWord,random,file2);

        accuracyValue=0;
        accuracyValue=controlOfAccuracy(copyOfSecretWord,numOfLettersSecretWord,randomWord,accuracyValue,numOfLettersRandomWord);

        if(accuracyValue==numOfLettersSecretWord){
        printf("CONGRATULATIONS! COMPUTER FOUND THE WORD IN %d. STEPS =%s\n",numOfSteps,randomWord);

        return *randomWord;
        }
        else{
            printf("WORD NOT FOUND IN THE DICTIONARY\n");
            printf("THE WORD IS ADDING TO THE DICTIONARY...\n");
            addToDictionary(secretWord,file1);
            printf("THE WORD IS ADDED TO THE DICTIONARY.\n");
            return 0;
            }
    }
    else
    {
        accuracyValue=0;
        printf("YOU VIEWED THE %d. STEP!\n",numOfSteps);
        numOfSteps++;
        getchar();
        computerFindsTheWord(numOfWords,secretWord,file1,file2,file3,numOfSteps,alphabet);
    }
}

char* selectWord(int random,char*selectedWord,FILE*file1)
{
    file1=fopen("dictionary.txt","r");
    int i=0;
    char line[128];
    while(fgets(line,sizeof line,file1)!=NULL)
    {
        i++;
        if(i==random)
        {
            strcpy(selectedWord,line);
        }
    }
    fclose(file1);
    return *selectedWord;
}

int controlOfNormalAccuracy(int numOfLettersSecretWord,int numOfLettersSelectedWord,char*copyOfSelectedWord,char*copyOfEnteredWord,int normalAccuracyValue)
{
    for(int k=0;k<numOfLettersSelectedWord;k++){
        for(int l=0;l<numOfLettersSecretWord;l++){
            if(copyOfSelectedWord[k]==copyOfEnteredWord[l]){
                normalAccuracyValue++;
                copyOfSelectedWord[k]=0;
                copyOfEnteredWord[l]=1;
                break;
            }
        }
    }
    return normalAccuracyValue;
}


int controlOfEnteredWordAccuracy(int numOfLettersSelectedWord,char*enteredWord,char*selectedWord,int accuracyValue)
{
    for(int k=0;k<numOfLettersSelectedWord;k++)
    {
        if(selectedWord[k]==enteredWord[k])
        {
            accuracyValue++;
        }
    }
    return accuracyValue;
}

int userFindsTheWord(char*selectedWord,int numOfLettersSelectedWord,FILE*file1,int numOfAttempts)
{
    printf("ENTER THE WORD\n");
    char enteredWord[20];
    scanf("%s",&enteredWord);

    char copyOfEnteredWord[20]={""};
    char copyOfSelectedWord[20]={""};

    int numOfLettersSecretWord=0;
    numOfLettersSecretWord=findingNumOfLettersSecretWord(enteredWord,numOfLettersSecretWord);
    printf("%d\n",numOfLettersSecretWord);
    printf("%s\n",enteredWord);

    copying(enteredWord,copyOfEnteredWord);
    copying(selectedWord,copyOfSelectedWord);

    int normalAccuracyValue=0;
    normalAccuracyValue=controlOfNormalAccuracy(numOfLettersSecretWord,numOfLettersSelectedWord,copyOfSelectedWord,copyOfEnteredWord,normalAccuracyValue);
    printf("NORMAL ACCURACY     =%d\n",normalAccuracyValue);

    copying(enteredWord,copyOfEnteredWord);
    copying(selectedWord,copyOfSelectedWord);

    int cartesianAccuracyValue=0;
    cartesianAccuracyValue=controlOfCartesianAccuracy(numOfLettersSecretWord,numOfLettersSelectedWord,copyOfSelectedWord,copyOfEnteredWord,cartesianAccuracyValue);
    printf("CARTESIAN ACCURACY  =%d\n",cartesianAccuracyValue);

    int accuracyValue=0;
    accuracyValue=controlOfEnteredWordAccuracy(numOfLettersSelectedWord,enteredWord,selectedWord,accuracyValue);

    if(accuracyValue==numOfLettersSelectedWord)
    {
        printf("YOU FOUND THE RIGHT WORD IN THE %d. TRIAL\n",numOfAttempts+1);
        printf("RIGHT WORD=%s",selectedWord);
        return *selectedWord;
    }
    else
    {
        numOfAttempts++;
        printf("YOU FAILED IN YOUR %d. TRIAL!\n",numOfAttempts);
        accuracyValue=0;

        userFindsTheWord(selectedWord,numOfLettersSelectedWord,file1,numOfAttempts);
    }
}

void selections()
{
    printf("WORD FINDING GAME\n");
    printf("1.COMPUTER FIND THE WORD YOU KEEP\n");
    printf("2.YOU FIND THE WORD KEEPED BY THE COMPUTER\n");
    printf("9.NUMBER OF WORDS IN THE DICTIONARY\n");
    printf("0.EXIT THE GAME\n");
}

int main()
{
    srand(time(NULL));

    FILE *file1;

    FILE *file2;

    FILE *file3;
    int choice;
    int numOfWords=0;
    char secretWord[15];
    char selectedWord[20];

    int random=0;
    char alphabet[30]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','s','r','t','u','v','w','x','y','z'};

    do
    {
        numOfWords=writingFileForUse(numOfWords,file1,file2);
        random=1+rand()%numOfWords;
        selections();
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                numOfWords=writingFileForUse(numOfWords,file1,file2);
                printf("ENTER THE WORD:");
                scanf("%s",&secretWord);
                printf("%s\n",secretWord);

                int numOfSteps=1;
                getchar();

                computerFindsTheWord(numOfWords,secretWord,file1,file2,file3,numOfSteps,alphabet);
                break;
            case 2:
                selectWord(random,selectedWord,file1);
                int numOfLettersSelectedWord=0;
                numOfLettersSelectedWord=findingNumOfLettersSecretWord(selectedWord,numOfLettersSelectedWord);
                numOfLettersSelectedWord--;
                int numOfAttempts=0;
                printf("%s\n",selectedWord);
                printf("%d\n",numOfLettersSelectedWord);
                printf("%d\n",numOfAttempts);
                userFindsTheWord(selectedWord,numOfLettersSelectedWord,file1,numOfAttempts);
                break;
            case 9:
                numOfWords=0;
                numOfWords=writingFileForUse(numOfWords,file1,file2);
                printf("%d\n",numOfWords);
                printf("\n\n\n");
                break;

            case 0:
                break;

            default:
                printf("WRONG INPUT!!!!!!\n");
                break;
        }
    }while(choice!=0);
}
