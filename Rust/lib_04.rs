#[cfg(test)]
mod tests {

    // use std::cmp::min;

    // use std::cmp::max;

    struct Solution {}
    // impl Solution {
    //     pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
    //         let (a, b) = if nums1.len() <= nums2.len() {
    //             (&nums1, &nums2)
    //         } else {
    //             (&nums2, &nums1)
    //         };
    //         let mut res = 10.2;
    //         let mut l = 0;
    //         let mut h = a.len();
    //         let total_len = a.len() + b.len();
    //         while l <= h {
    //             let m = (l + h) / 2;
    //             let n = (total_len + 1) / 2 - m;
    //             // println!("{} {}", m, n);
    //             let v1 = if m > 0 { Some(a[m - 1]) } else { None };
    //             let v2 = if m < a.len() { Some(a[m]) } else { None };
    //             let v3 = if n > 0 { Some(b[n - 1]) } else { None };
    //             let v4 = if n < b.len() { Some(b[n]) } else { None };
    //             // println!("{:?} {:?} {:?} {:?}", v1, v2, v3, v4);
    //             let cond1 = if let (Some(s), Some(t)) = (v1, v4) {
    //                 s <= t
    //             } else {
    //                 true
    //             };
    //             let cond2 = if let (Some(s), Some(t)) = (v3, v2) {
    //                 s <= t
    //             } else {
    //                 true
    //             };
    //             // println!("{} {}", cond1, cond2);
    //             if cond1 && cond2 {
    //                 res = if total_len % 2 == 1 {
    //                     (match (v1, v3) {
    //                         (Some(v), None) | (None, Some(v)) => v,
    //                         _ => max(v1.unwrap(), v3.unwrap()),
    //                     }) as f64
    //                 } else {
    //                     (match (v1, v3) {
    //                         (Some(v), None) | (None, Some(v)) => v,
    //                         _ => max(v1.unwrap(), v3.unwrap()),
    //                     } + match (v2, v4) {
    //                         (Some(v), None) | (None, Some(v)) => v,
    //                         _ => min(v2.unwrap(), v4.unwrap()),
    //                     }) as f64
    //                         / 2.0
    //                 };
    //                 break;
    //             } else if cond1 {
    //                 l = m + 1
    //             } else {
    //                 h = m - 1
    //             }
    //         }
    //         res
    //     }
    // }
    impl Solution {
        pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
            let len1 = nums1.len();
            let len2 = nums2.len();
            let mut res = Vec::new();
            let (mut i, mut j) = (0, 0);
            while i < len1 && j < len2 {
            	if nums1[i] > nums2[j] {
            		res.push(nums2[j]);
            		j += 1;
            	}else {
            		res.push(nums1[i]);
            		i += 1;
            	}
            }
            while i < len1 {
            	res.push(nums1[i]);
            	i += 1;
            }
            while j < len2 {
            	res.push(nums2[j]);
            	j += 1;
            }
            let len_res = res.len();
           	if len_res % 2 == 1 {
           		return res[len_res / 2] as f64
           	}else{
           		return (res[len_res / 2] as f64 + res[len_res / 2 - 1] as f64) / 2.0
           	}
        }
    }
    #[test]
    fn it_works() {
        assert_eq!(
            3.0,
            Solution::find_median_sorted_arrays(vec![1, 2], vec![3, 4, 5])
        );
    }
}
