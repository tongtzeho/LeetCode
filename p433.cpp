class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if (bank.empty()) return -1;
        list<int> notfound;
        int banksize = bank.size();
        int *nextlst = new int[banksize];
        int *chngnextlst = new int[banksize];
        int startlen = start.length();
        int endlen = end.length();
        if (startlen != endlen) return -1;
        int endid = -1;
        int nextsize = 0;
        int chngnextlstsize = 0;
        int i, j, k, cnt, len;
        for (i = 0; i < banksize; i++) {
            if (bank[i] == end) {
                endid = i;
            }
            len = bank[i].length();
            if (len == startlen) {
                cnt = 0;
                for (k = 0; k < startlen; k++) {
                    if (start[k] != bank[i][k]) {
                        cnt++;
                        if (cnt >= 2) {
                            break;
                        }
                    }
                }
                if (cnt == 1) {
                    if (endid == i) {
                        return 1;
                    }
                    nextlst[nextsize++] = i;
                } else if (cnt != 0) {
                    notfound.push_back(i);
                }
            }
        }
        if (endid == -1) return -1;
        int result = 2;
        while (nextsize) {
            chngnextlstsize = 0;
            list<int>::iterator iter, jter;
            for (iter = notfound.begin(); iter != notfound.end(); ) {
                j = *iter;
                for (i = 0; i < nextsize; i++) {
                    cnt = 0;
                    for (k = 0; k < startlen; k++) {
                        if (bank[j][k] != bank[nextlst[i]][k]) {
                            cnt++;
                            if (cnt >= 2) {
                                break;
                            }
                        }
                    }
                    if (cnt == 1) {
                        break;
                    }
                }
                if (i != nextsize) {
                    if (j == endid) return result;
                    chngnextlst[chngnextlstsize++] = j;
                    jter = iter;
                    iter++;
                    notfound.erase(jter);
                } else {
                    iter++;
                }
            }
            nextsize ^= chngnextlstsize;
            chngnextlstsize ^= nextsize;
            nextsize ^= chngnextlstsize;
            int *tmp = nextlst;
            nextlst = chngnextlst;
            chngnextlst = tmp;
            result++;
        }
        return -1;
    }
};