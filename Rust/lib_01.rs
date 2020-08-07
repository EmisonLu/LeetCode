#[cfg(test)]
mod tests {
    use std::collections::HashMap;

    struct Solution {}
    // 暴力法
    // impl Solution {
    //     pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
    //         let len = nums.len();
    //         let mut a;
    //         for i in 0..len {
    //             a = target - nums[i];
    //             for j in i + 1..len {
    //                 if nums[j] == a {
    //                     return vec![i as i32, j as i32]
    //                 }
    //             }
    //         }
    //         panic!()
    //     }
    // }
    //
    //
    //
    // 哈希法
    impl Solution {
        pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
            let mut map: HashMap<i32, usize> = HashMap::new();

            for (i, &num) in nums.iter().enumerate() {
                if let Some(&pos) = map.get(&(target - num)) {
                    return vec![pos as i32, i as i32];
                }
                map.insert(num, i);
            }
            panic!()
        }
    }

    #[test]
    fn it_works() {
        assert_eq!(vec![0, 3], Solution::two_sum(vec![2, 7, 11, 15], 17));
    }
}
