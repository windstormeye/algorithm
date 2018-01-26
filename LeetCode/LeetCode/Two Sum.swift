//
//  Two Sum.swift
//  LeetCode
//
//  Created by pjpjpj on 2018/1/25.
//  Copyright © 2018年 #incloud. All rights reserved.
//

import Cocoa

class Two_Sum: NSObject {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var final: [Int] = [0, 0]
        var index: Int = 0
        for _ in 0..<nums.count {
//            let result = target - nums[index]
//            if nums.contains(result) {
//                if nums.index(of: result)! != index {
//                    final = [nums.index(of: result)!, index]
//                }
//            }
            print(index)
            var index_i:Int = index+1
            for _ in index+1..<nums.count {
                if target == nums[index] + nums[index_i] {
                    final = [index, index_i]
                }
                index_i = index_i + 1
            }
            index = index + 1
        }
        return final
    }
}


// 543 157
// 722 207


