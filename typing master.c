#include <stdio.h>
#include <string.h>
#include <time.h>

// Function to calculate typing accuracy
float calculateAccuracy(const char *input, const char *original) {
    int correctChars = 0, i;
    int totalChars = strlen(original);

    for (i = 0; i < totalChars; i++) {
        if (input[i] == original[i]) {
            correctChars++;
        }
    }

    return ((float)correctChars / totalChars) * 100;
}

// Function to calculate typing speed in words per minute (WPM)
float calculateSpeed(int wordCount, double timeTaken) {
    return (wordCount / timeTaken) * 60; // WPM formula
}

int main() {
    const char sampleText[] = "C programming is fun and powerful."; // Predefined sample text
    char userInput[200]; // Buffer for user input
    int wordCount = 1;   // Count words in sample text
    int i;

    // Count the words in the sample text
    for (i = 0; sampleText[i] != '\0'; i++) {
        if (sampleText[i] == ' ') {
            wordCount++;
        }
    }

    printf("Welcome to Typing Master!\n\n");
    printf("Type the following text as quickly and accurately as you can:\n");
    printf("\"%s\"\n\n", sampleText);
    printf("Press ENTER to start typing...\n");

    // Wait for the user to start typing
    getchar();

    // Record the start time
    clock_t startTime = clock();

    // Get the user's input
    printf("\nYour Input: ");
    fgets(userInput, sizeof(userInput), stdin);

    // Record the end time
    clock_t endTime = clock();

    // Remove the newline character from the input
    userInput[strcspn(userInput, "\n")] = '\0';

    // Calculate the time taken
    double timeTaken = (double)(endTime - startTime) / CLOCKS_PER_SEC; // Time in seconds

    // Calculate speed and accuracy
    float accuracy = calculateAccuracy(userInput, sampleText);
    float speed = calculateSpeed(wordCount, timeTaken / 60); // Convert seconds to minutes

    // Display the results
    printf("\nTyping Test Results:\n");
    printf("---------------------\n");
    printf("Time Taken: %.2f seconds\n", timeTaken);
    printf("Typing Speed: %.2f WPM\n", speed);
    printf("Accuracy: %.2f%%\n", accuracy);

    return 0;
}
