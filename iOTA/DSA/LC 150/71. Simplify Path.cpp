class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;  // To store valid directory names
        string currDir = "";   // To store current directory name being processed
        int n = path.size();

        // Iterate through the given path string
        for (int i = 0; i < n; ++i) {
            if (path[i] == '/') {
                if (!currDir.empty()) {
                    // If "..", move up one directory by popping from stack
                    if (currDir == "..") {
                        if (!stack.empty()) {
                            stack.pop_back();
                        }
                    } 
                    // Ignore "." or empty string
                    else if (currDir != ".") {
                        stack.push_back(currDir);
                    }
                    // Reset current directory name
                    currDir = "";
                }
            } else {
                currDir += path[i];  // Build the current directory name
            }
        }

        // Check the last component after the loop
        if (!currDir.empty()) {
            if (currDir == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else if (currDir != ".") {
                stack.push_back(currDir);
            }
        }

        // Rebuild the simplified path from the stack
        string result = "/";
        for (int i = 0; i < stack.size(); ++i) {
            result += stack[i];
            if (i != stack.size() - 1) {
                result += "/";
            }
        }

        return result;
    }
};
