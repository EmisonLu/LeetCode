#[cfg(test)]
mod tests {
    struct Solution {}
    impl Solution {
        pub fn length_of_longest_substring(s: String) -> i32 {
            use std::cmp::max;
            let mut last: [i32; 128] = [-1; 128];
            let mut left = -1;
            let mut ans = 0;
            for (i, v) in s.chars().enumerate() {
                left = max(left, last[v as usize]);
                last[v as usize] = i as i32;
                ans = max(ans, (i as i32) - left);
            }
            return ans;
        }
    }
    #[test]
    fn it_works() {
        assert_eq!(
            3,
            Solution::length_of_longest_substring(String::from("abcaac"))
        );
    }
}
