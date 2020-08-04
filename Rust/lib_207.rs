#[cfg(test)]
mod tests {
    impl Solution {
        pub fn can_finish(&self, num_courses: i32, prerequisites: Vec<Vec<i32>>) -> bool {
            let num_courses = num_courses as usize;
            let mut p = vec![vec![]; num_courses];
            let mut c = vec![0; num_courses];
            for v in prerequisites {
                let (i, j) = (v[0] as usize, v[1] as usize);
                p[j].push(i);
                c[i] += 1;
            }
            let mut q = (0..num_courses).filter(|&i| c[i] == 0).collect::<Vec<_>>();
            while !q.is_empty() {
                let mut t = vec![];
                for i in q {
                    for &j in &p[i] {
                        c[j] -= 1;
                        if c[j] == 0 {
                            t.push(j)
                        }
                    }
                }
                q = t;
            }
            c.into_iter().all(|j| j == 0)
        }
    }

    #[test]
    fn it_works() {
        let num_courses = 2;
        let prerequisites = vec![vec![1, 0], vec![0, 1]];
        assert_eq!(true, can_finish(num_courses, prerequisites));
    }
}
