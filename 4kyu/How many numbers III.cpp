//https://www.codewars.com/kata/5877e7d568909e5ff90017e6
//This is an incomplete kata, so the solution won't work for every test.
//The reason for this is becuase my solution uses recursion for generating all combinations for 0 - n.
//This means that n increases the time to solve increases by N^2 time complexity.
//This solution will be stored in the repo only because I thought it was a unique solution and my first crack at recursive number //generation.

#include <cstdint>
#include <optional>
#include <tuple>
#include <vector>
#include <algorithm>

using out_t = std::tuple<std::uint32_t, std::uint64_t, std::uint64_t>;

void find_digits(std::uint32_t digit_sum, std::uint32_t digit_count, std::vector<int> &output, std::vector<int> current_digit)
{
  int current_digit_sum = 0;
  for(int i = 0; i < current_digit.size(); i++)
  {
    current_digit_sum += current_digit[i];
  }
  
  if(current_digit_sum > digit_sum)
  {
    return;
  }
  
  if(current_digit_sum == digit_sum && current_digit.size() == digit_count)
  {
    sort(current_digit.begin(), current_digit.end());
    int current_digit_into_int = 0;
    for(int i = 0; i < current_digit.size(); i++)
    {
      current_digit_into_int = current_digit_into_int * 10 + current_digit[i];
    }
    if(std::find(output.begin(), output.end(), current_digit_into_int) == output.end())
    {
      output.push_back(current_digit_into_int);
    }
  }
  
  if(current_digit.size() < digit_count && current_digit_sum <= digit_sum)
  {
    for(int i = 1; i <= 9 && current_digit_sum + i <= digit_sum; i++)
    {
      current_digit.push_back(i);
      find_digits(digit_sum, digit_count, output, current_digit);
      current_digit.pop_back();
    }
  }
}

std::optional<out_t> find_all(std::uint32_t digit_sum, std::uint32_t digit_count) {
  
  std::vector<int> output;
  std::vector<int> current_digit;
  
  find_digits(digit_sum, digit_count, output, current_digit);

  if(output.size() == 0)
  {
    return std::nullopt;
  }
  else
  {
    out_t myTuple = std::make_tuple(output.size(), output[0], output[output.size() - 1]);
    return myTuple;
  }
}