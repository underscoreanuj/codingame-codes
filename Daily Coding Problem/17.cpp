/*
 *
 * Good morning! Here's your coding interview problem for today.
 * This problem was asked by Google.
 * Suppose we represent our file system by a string in the following manner:
 * The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

    -----------------------------------------
    |                dir                    |
    |                    subdir1            |
    |                    subdir2            |
    |                        file.ext       |
    -----------------------------------------              

 * The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.
 * The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

    -----------------------------------------
    |                dir                    |
    |                    subdir1            |
    |                        file1.ext      |
    |                        subsubdir1     |
    |                    subdir2            |
    |                        subsubdir2     |
    |                            file2.ext  |
    -----------------------------------------

 * The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.
 * We are interested in finding the longest (number of characters) absolute path to a file within our file system. For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).
 * Given a string representing the file system in the above format, return the length of the longest absolute path to a file in the abstracted file system. If there is no file in the system, return 0.
 * 
 * Note:
 * The name of a file contains at least a period and an extension.
 * The name of a directory or sub-directory will not contain a period.
 * 
 * 
 * Online Judge: https://leetcode.com/problems/longest-absolute-file-path/
 * 
 * 
*/

class Solution
{
public:
   int lengthLongestPath(string input)
   {
      istringstream paths(input);
      string path;
      int max_path_len = 0, depth = 0;

      unordered_map<int, int> depth_map;

      while (getline(paths, path))
      {
         depth = path.find_last_of("\t");
         depth = (depth == string::npos) ? 0 : depth + 1;

         if (path.find(".") != string::npos)
         { // it is a file
            max_path_len = max(max_path_len, int(depth_map[depth] + path.length()));
         }
         else
         {
            depth_map[depth + 1] = depth_map[depth] + path.length() - depth;
         }
      }

      return max_path_len;
   }
};
