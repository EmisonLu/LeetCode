#[cfg(test)]
mod tests {
    struct Solution {}
    impl Solution {
        pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
            let len = nums.len();
            let mut a;

            for i in 0..len {
                a = target - nums[i];
                for j in i + 1..len {
                    if nums[j] == a {
                        return vec![i as i32, j as i32]
                    }
                }
            }
            [].to_vec()
        }
    }
    #[test]
    fn it_works() {
        let nums = vec![2, 7, 11, 15];
        let target = 17;
        let result = vec![0, 3];
        assert_eq!(result, Solution::two_sum(nums, target));
    }
}
