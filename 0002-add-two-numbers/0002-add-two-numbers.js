/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    const iter = (n1, n2, carry = 0) => {
        if(!n1 && !n2 && !carry) return null;
        const sum = (n1?.val || 0) + (n2?.val || 0) + carry;
        const next = iter(n1?.next, n2?.next, Math.floor(sum / 10));
        return new ListNode(sum % 10, next); 
    }
    return iter(l1, l2);
};