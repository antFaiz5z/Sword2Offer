//
// Created by faiz on 18-4-25.
//

#ifndef JIANZHIOFFER_LIST_H
#define JIANZHIOFFER_LIST_H

#include "Utility.h"

#include <vector>
#include <stack>

using namespace std;

class Data_Structure {

public:

    /*
     * 5. 替换空格
     * 请实现一个函数，将一个字符串中的空格替换成“%20”。
     * 例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
     */
    void replace_space(char *str, int length);
    void replace_space_standard(char *str, int length);
    static void local_main_replace_space();
    /*
     * 4. 二维数组中的查找
     * 在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
     * 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
     */
    vector<vector<int>> get_array(int m, int n);

    bool find_mine(int target, vector<vector<int> > array);
    bool find_standard(int target, vector<vector<int> > array);
    static void local_main_find();

    /*
     * 6. 从尾到头打印链表
     * 输入一个链表，从尾到头打印链表每个节点的值。
     */
    std::vector<int> printListFromTailToHead(ListNode* head);
    static void local_main_printListFromTailToHead();

    /*
     * 9. 用两个栈实现队列
     * 用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
     */
    void push_2(int node);
    int pop_2();
    static void local_main_2stacks_1queue();

    /*
     * 27. 二叉树的镜像
     * 操作给定的二叉树，将其变换为源二叉树的镜像。
     */
    void mirror_tree(TreeNode *root);
    static void local_main_mirror_tree();

    /*
     * 29. 顺时针打印矩阵
     * 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
     * 例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
     * 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
     */
    vector<int> print_matrix(vector<vector<int>> matrix);
    static void local_main_print_matrix();

    /*
     * 30. 包含 min 函数的栈
     * 定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数。
     */
    void push(int value);
    void pop();
    int top();
    int min();
    static void local_main_stack_min();

    /*
     * 58.2 左旋转字符串
     * 汇编语言中有一种移位指令叫做循环左移（ROL），
     * 现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
     * 对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
     * 例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，
     * 即“XYZdefabc”。是不是很简单？OK，搞定它！
     */
    string left_rotate_string(string str, int n);//取巧
    string left_rotate_string_standard(string str, int n);
    string left_rotate_string_standard_II(string str, int n);
    static void local_main_left_rotate_string();

    /*
     * 58.1 翻转单词顺序列
     * 牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，
     * 写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，
     * 但却读不懂它的意思。例如，“student. a am I”。后来才意识到，
     * 这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。
     * Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
     */
    string reverse_sentence(string str);
    static void local_main_reverse_sentence();

    /*
     * 22. 链表中倒数第 K 个结点
     * 输入一个链表，输出该链表中倒数第k个结点。
     *
     * 思路：
     * 设链表的长度为 N。设两个指针 P1 和 P2，先让 P1 移动 K 个节点，
     * 则还有 N - K 个节点可以移动。此时让 P1 和 P2 同时移动，
     * 可以知道当 P1 移动到链表结尾时，P2 移动到 N - K 个节点处，该位置就是倒数第 K 个节点。
     */
    ListNode *find_Kth2tail_mine(ListNode *head, unsigned int k);
    ListNode *find_Kth2tail_mine_backtracking(ListNode *now, int &counter, int k);
    ListNode *find_Kth2tail(ListNode *head, unsigned int k);
    static void local_main_find_Kth2tail();

    /*
     * 23. 链表中环的入口结点
     * 一个链表中包含环，请找出该链表的环的入口结点。要求不能使用额外的空间。
     *
     * 思路：
     * 使用双指针，一个指针 fast 每次移动两个节点，一个指针 slow 每次移动一个节点。
     * 因为存在环，所以两个指针必定相遇在环中的某个节点上。
     * 假设相遇点在下图的 y6 位置，此时 fast 移动的节点数为 x+2y+z，slow 为 x+y，
     * 由于 fast 速度比 slow 快一倍，因此 x+2y+z=2(x+y)，得到 x=z。
     * 在相遇点，slow 要到环的入口点还需要移动 z 个节点，如果让 fast 重新从头开始移动，
     * 并且速度变为每次移动一个节点，那么它到环入口点还需要移动 x 个节点。
     * 在上面已经推导出 x=z，因此 fast 和 slow 将在环入口点相遇。
     */
    ListNode *entry_node_of_loop(ListNode *head);
    static void local_main_entry_node_of_loop();

    /*
     * 24. 反转链表
     * 输入一个链表，反转链表后，输出新链表的表头。
     */
    ListNode *reverse_list_recur(ListNode *head);
    ListNode *reverse_list_recurII(ListNode *head);
    ListNode *reverse_list_itera(ListNode *head);
    static void local_main_reverse_list();

    /*
     * 26. 树的子结构
     * 输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
     */
    bool is_sub_tree(TreeNode *root1, TreeNode *root2);
    bool recur_is_sub_tree(TreeNode *root1, TreeNode *root2);
    static void local_main_is_sub_tree();

    /*
     * 28 对称的二叉树
     * 请实现一个函数，用来判断一颗二叉树是不是对称的。
     * 注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
     */
    bool is_symmetrical(TreeNode *root);
    bool recur_is_symmetrical(TreeNode *root1, TreeNode *root2);
    static void local_main_is_symmetrical();

    /*
     * 31. 栈的压入、弹出序列
     * 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
     * 假设压入栈的所有数字均不相等。
     * 例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
     * 但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
     */
    bool is_pop_order(vector<int> push, vector<int> pop);
    static void local_main_is_pop_order();

    /*
     * 32.1 从上往下打印二叉树
     * 从上往下打印出二叉树的每个节点，同层节点从左至右打印。
     */
    static vector<int> com_tree_2_vector(TreeNode *root);//完全二叉树，层次遍历,忽略空节点
    /*
     * 32.2 把二叉树打印成多行
     */
    static vector<vector<int>> com_tree_2_vector_vector(TreeNode *root);//完全二叉树，层次遍历,忽略空节点
    /*
     * 32.3 按之字形顺序打印二叉树
     * 请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
     * 第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
     */
    static vector<vector<int>> com_tree_2_vector_vector_zigzag(TreeNode *root);//完全二叉树，层次遍历,忽略空节点
    static void local_main_tree_2_vector();

    /*
     * 33. 二叉搜索树的后序遍历序列
     * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
     * 如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
     */
    bool is_seq_of_bst(vector<int> sequence);
    bool is_seq_of_bst_judge(vector<int>& sequence, int left, int right);
    static void local_main_is_seq_of_bst();

    /*
     * 34. 二叉树中和为某一值的路径
     * 输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
     * 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
     * (注意: 在返回值的list中，数组长度大的数组靠前)//TODO:???
     */
    vector<vector<int>> find_path(TreeNode *root, int expect_num);
    void find_path_backtracking(TreeNode *root, int expect_num, vector<vector<int>> &ret, vector<int> &path);
    static void local_main_find_path();

    /*
     * 35. 复杂链表的复制
     * 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，
     * 另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
     * （注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
     *
     * 思路：
     * 第一步，在每个节点的后面插入复制的节点。
     * 第二步，对复制节点的 random 链接进行赋值。
     * 第三步，拆分。
     */
    RandomListNode *clone(RandomListNode *head);
    static void local_main_clone();

    /*
     * 36. 二叉搜索树与双向链表
     * 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
     * 要求不能创建任何新的结点，只能调整树中结点指针的指向。
     */
    TreeNode* tree_2_doubly_list_mine(TreeNode *root);//仅限完全二叉树
    TreeNode* tree_2_doubly_list_mine_backtracking(TreeNode *&new_root, TreeNode *root, bool right);
    TreeNode* tree_2_doubly_list(TreeNode *root);//TODO:error
    void tree_2_doubly_list_backtracking(TreeNode *root, TreeNode* pre, TreeNode *head);
    static void local_main_tree_2_doubly_list();

    /*
     * 37. 序列化二叉树
     * 请实现两个函数，分别用来序列化和反序列化二叉树
     */
    char *serialize(TreeNode *root);
    void serialize_recur(TreeNode *root, vector<int> &str);
    TreeNode *deserialize(char* str);
    TreeNode *deserialize_recur(int *&index);
    static void local_main_serialize();

    /*
     * 52. 两个链表的第一个公共结点
     * 输入两个链表，找出它们的第一个公共结点。
     * 注意：题目没有明确两链表一定相交
     */
    ListNode *find_first_common_node(ListNode *head1, ListNode *head2);
    static void local_main_find_first_common_node();

    /*
     * 59. 滑动窗口的最大值
     * 给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
     * 例如，如果输入数组 {2, 3, 4, 2, 6, 2, 5, 1} 及滑动窗口的大小 3，
     * 那么一共存在 6 个滑动窗口，他们的最大值分别为 {4, 4, 6, 6, 6, 5}。
     *
     * 注意：C++无法使用优先队列方法解，由于priority_queue无remove方法
     * 因此使用双向队列
     */
    vector<int> max_in_windows(const vector<int> &num, unsigned int size);
    static void local_main_max_in_windows();

private:

    std::stack<int> s1;
    std::stack<int> s2;

    std::stack<int> s3;
    std::stack<int> s4;
};

#endif //JIANZHIOFFER_LIST_H
