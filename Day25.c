Problem1: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.
Input:
- First line: integer n (number of nodes)
- Second line: n space-separated integers (linked list elements)
- Third line: integer key (element to be counted)
Output:
- Print the number of times the key appears in the linked list
Example:
Input:
6
10 20 30 20 40 20
20
Output:
3
Explanation:
Traverse the linked list from head to end. Each time a node's data matches the given key, increment a counter. After traversal, print the final count.

Answer:
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def create_linked_list(values):
    if not values:
        return None
    
    head = Node(values[0])
    current = head
    
    for value in values[1:]:
        new_node = Node(value)   
        current.next = new_node
        current = new_node
    
    return head

def count_occurrences(head, key):
    count = 0
    current = head
    
    while current:
        if current.data == key:
            count += 1
        current = current.next
    
    return count


n = int(input())
elements = list(map(int, input().split()))
key = int(input())

head = create_linked_list(elements)

result = count_occurrences(head, key)

print(result)

Problem2:Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.
Do not modify the linked list.
Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
Example 2:
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
Example 3:
Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
Constraints:
The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
Follow up: Can you solve it using O(1) (i.e. constant) memory?

Answer:
class ListNode:
    def __init__(self, val=0):
        self.val = val
        self.next = None


def detectCycle(head):
    if not head or not head.next:
        return None

    slow = head
    fast = head

    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next

        if slow == fast:  
            slow = head
            while slow != fast:
                slow = slow.next
                fast = fast.next
            
            return slow 

    return None
