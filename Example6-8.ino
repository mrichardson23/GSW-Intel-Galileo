int getHours() {
	char output[5];
	system("curl http://nextmakemagazine.appspot.com/simple > re sponse.txt");
	FILE *fp;
	fp = fopen("response.txt", "r");
	fgets(output, 5, fp);
	fclose(fp);
	return atoi(output);
}