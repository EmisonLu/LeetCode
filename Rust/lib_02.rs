#[cfg(test)]
mod tests {
    #[derive(PartialEq, Eq, Clone, Debug)]
    pub struct ListNode {
        pub val: i32,
        pub next: Option<Box<ListNode>>,
    }

    impl ListNode {
        #[inline]
        fn new(val: i32) -> Self {
            ListNode { next: None, val }
        }
    }
    struct Solution {}
    impl Solution {
        pub fn add_two_numbers(
            l1: Option<Box<ListNode>>,
            l2: Option<Box<ListNode>>,
        ) -> Option<Box<ListNode>> {
            let mut sum = 0;
            let (mut l1, mut l2) = (l1, l2);
            let mut l = None;
            let mut p = &mut l;

            loop {
            	if let None = l1 {
                    if let None = l2 {
                        break;
                    }
                }
                if let Some(v1) = l1 {
                    sum += v1.val;
                    l1 = v1.next;
                }
                if let Some(v2) = l2 {
                    sum += v2.val;
                    l2 = v2.next;
                }

                *p = Some(Box::new(ListNode::new(sum % 10)));
                sum /= 10;
                if let Some(p_box_node) = p {
                    p = &mut p_box_node.next;
                }
            }
            if sum != 0 {
                *p = Some(Box::new(ListNode::new(sum)));
            }

            l
        }
    }
    #[test]
    fn it_works() {
        // 2->4->3
        let mut p = Some(Box::new(ListNode::new(2)));
        let mut l1 = &mut p;
        if let Some(x) = l1 {
            l1 = &mut x.next;
        }
        // println!("{:?}",l1);
        *l1 = Some(Box::new(ListNode::new(4)));
        if let Some(x) = l1 {
            l1 = &mut x.next;
        }
        *l1 = Some(Box::new(ListNode::new(3)));

        // 5->6->5
        let mut q = Some(Box::new(ListNode::new(5)));
        let mut l2 = &mut q;
        if let Some(x) = l2 {
            l2 = &mut x.next;
        }
        *l2 = Some(Box::new(ListNode::new(6)));
        if let Some(x) = l2 {
            l2 = &mut x.next;
        }
        *l2 = Some(Box::new(ListNode::new(5)));

        // 7->0->9
        let mut q_p = Some(Box::new(ListNode::new(7)));
        let mut l3 = &mut q_p;
        if let Some(x) = l3 {
            l3 = &mut x.next;
        }
        *l3 = Some(Box::new(ListNode::new(0)));
        if let Some(x) = l3 {
            l3 = &mut x.next;
        }
        *l3 = Some(Box::new(ListNode::new(9)));

        assert_eq!(q_p, Solution::add_two_numbers(p, q));
    }
}
