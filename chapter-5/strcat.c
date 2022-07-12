//concatenate t to the end of s, s must be large enough
void strcat(char s[], char t[]) {
    int i, j;
    i = j = 0;
    while(s[i] != '\0') i++;
    while((s[i++] = t[j++]) != '\0');
}

//same as strcat, but uses pointers
void strcatp(char *s, char *t) {
    while(*s++ != '\0');
    while((*s++ = *t++) != '\0');
}