//iterative
int lastOccurrence(string str, char target) {
    for (int i = str.length() - 1; i >= 0; i--) {
        if (str[i] == target) {
            return i;
        }
    }
    return -1;
}


//find_last_of
int lastOccurrence(string str, char target) {
    size_t pos = str.find_last_of(target);
    return (pos != string::npos) ? pos : -1;
}


//recursion
int lastOccurrenceHelper(string str, char target, int index) {
    if (index == str.length()) return -1;
    int next = lastOccurrenceHelper(str, target, index + 1);
    if (next == -1 && str[index] == target) return index;
    return next;
}

int lastOccurrence(string str, char target) {
    return lastOccurrenceHelper(str, target, 0);
}


//reverse iterator
int lastOccurrence(string str, char target) {
    for (auto it = str.rbegin(); it != str.rend(); ++it) {
        if (*it == target) {
            return str.rend() - it - 1;
        }
    }
    return -1;
}

