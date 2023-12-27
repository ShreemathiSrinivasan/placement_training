1.
public class ProductArrayExceptSelf {

    public static int[] productExceptSelf(int[] nums) {
        int n = nums.length;

        int[] leftProducts = new int[n];
        int[] rightProducts = new int[n];
        int[] result = new int[n];

        // Calculate left products
        leftProducts[0] = 1;
        for (int i = 1; i < n; i++) {
            leftProducts[i] = leftProducts[i - 1] * nums[i - 1];
        }

        // Calculate right products
        rightProducts[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            rightProducts[i] = rightProducts[i + 1] * nums[i + 1];
        }

        // Calculate result
        for (int i = 0; i < n; i++) {
            result[i] = leftProducts[i] * rightProducts[i];
        }

        return result;
    }

    public static void main(String[] args) {
        int[] input = {1, 2, 3, 4};
        int[] output = productExceptSelf(input);

        // Print the result
        for (int num : output) {
            System.out.print(num + " ");
        }
    }
}

2.

import java.util.ArrayList;
import java.util.List;

public class Permutations {

    public static List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        generatePermutations(nums, new ArrayList<>(), result);
        return result;
    }

    private static void generatePermutations(int[] nums, List<Integer> current, List<List<Integer>> result) {
        if (current.size() == nums.length) {
            result.add(new ArrayList<>(current));
            return;
        }

        for (int num : nums) {
            if (!current.contains(num)) {
                current.add(num);
                generatePermutations(nums, current, result);
                current.remove(current.size() - 1);
            }
        }
    }

    public static void main(String[] args) {
        int[] input = {1, 4, 3};
        List<List<Integer>> output = permute(input);

        // Print the result
        System.out.println(output);
    }
}

3.

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class ClubbedWords {

    public static List<String> findClubbedWords(String[] words) {
        Set<String> wordSet = new HashSet<>();
        for (String word : words) {
            wordSet.add(word);
        }

        List<String> result = new ArrayList<>();
        for (String word : words) {
            if (isClubbedWord(word, wordSet)) {
                result.add(word);
            }
        }

        return result;
    }

    private static boolean isClubbedWord(String word, Set<String> wordSet) {
        for (int i = 1; i < word.length(); i++) {
            String prefix = word.substring(0, i);
            String suffix = word.substring(i);

            if (wordSet.contains(prefix) && wordSet.contains(suffix)) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        String[] input = {"mat", "mate", "matbellmates", "bell", "bellmatesbell", "butterribbon", "butter", "ribbon"};
        List<String> output = findClubbedWords(input);

        // Print the result
        System.out.println(output);
    }
}
