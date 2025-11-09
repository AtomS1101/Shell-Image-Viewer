#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void showImage(char *filename[]) {
	FILE *imageFile = fopen(*filename, "rb");
	if (imageFile == NULL) {
		printf("show: Error opening file\n");
	}
	printf("success\n");
	unsigned char  imageData;
	while (fread(&imageData, sizeof(unsigned char), 1, imageFile) == 1) {
		printf("%da", imageData);
	}
	fclose(imageFile);
}

void showVideo(char *filename[]) {
	printf("showing video\n");
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Usage: show image_file\n");
		return 1;
   }

	char *filename = argv[1];
	char *dot = strrchr(filename, '.'); // find the last '.'

	if (dot == NULL) {
	   printf("Could　not recognize the file type\n");
	} else if (strcmp(dot, ".jpeg") ==0 || strcmp(dot, ".jpg") == 0) {
		showImage(&filename);
	} else if (strcmp(dot, ".mp4") == 0) {
		showVideo(&filename);
	} else {
		printf("show: \"%s\" is not unsupported.\n", dot);
		return 1;
	}

	return 0;
}
