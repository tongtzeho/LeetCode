int compareVersion(char* version1, char* version2) {
    int pos1 = 0;
    int pos2 = 0;
    while (version1[pos1] != '\0' || version2[pos2] != '\0')
    {
        int v1 = 0;
        int v2 = 0;
        if (version1[pos1] != '\0')
        {
            int newpos1 = pos1+1;
            char c;
            while (version1[newpos1] != '.' && version1[newpos1] != '\0')
            {
                newpos1++;
            }
            c = version1[newpos1];
            version1[newpos1] = '\0';
            v1 = atoi(version1+pos1);
            if (c == '\0') pos1 = newpos1;
            else pos1 = newpos1+1;
        }
        if (version2[pos2] != '\0')
        {
            int newpos2 = pos2+1;
            char c;
            while (version2[newpos2] != '.' && version2[newpos2] != '\0')
            {
                newpos2++;
            }
            c = version2[newpos2];
            version2[newpos2] = '\0';
            v2 = atoi(version2+pos2);
            if (c == '\0') pos2 = newpos2;
            else pos2 = newpos2+1;
        }
        if (v1 < v2) return -1;
        else if (v1 > v2) return 1;
    }
    return 0;
}