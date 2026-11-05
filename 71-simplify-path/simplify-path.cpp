
class Solution {
public:
    string simplifyPath(string path) {

        stack<string> st;
        stringstream ss(path);
        string dir;

        // Split path using '/'
        while (getline(ss, dir, '/')) {

            // Ignore empty directories and current directory
            if (dir == "" || dir == ".") {
                continue;
            }

            // Move to parent directory
            else if (dir == "..") {

                if (!st.empty()) {
                    st.pop();
                }
            }

            // Valid directory name
            else {
                st.push(dir);
            }
        }

        // Construct simplified path
        string ans = "";

        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        // If stack is empty, return root
        if (ans.empty()) {
            return "/";
        }

        return ans;
    }
};
