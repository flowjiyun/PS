## Sliding Window

- 유형
    - subarray를 유효하게 만드는 조건이 주어 진다. 합해서 몇 이하 어떤 숫자의 포함 빈도 등
    - 여러 subarray안에서 최적의 subarray 를 찾는 문제가 나옴 혹은 몇개의 subarray가 나오는지?
- 예시
    - 합이 k보다 작거나 같은 가장 긴 하위 배열을 구합니다.
    - "0"이 하나 이상 있는 가장 긴 부분 문자열을 구합니다.
    - k보다 작은 곱을 갖는 서브 배열의 개수 찾기
- 수도 코드

```cpp
function fn(arr):
    left = 0
    for (int right = 0; right < arr.length; right++):
        Do some logic to "add" element at arr[right] to window

        while WINDOW_IS_INVALID:
            Do some logic to "remove" element at arr[left] from window
            left++

        Do some logic to update the answer
```

- 효율적인 이유
    - 배열에서 전체 subarray를 구하는 것은 O(n^2)→ partial sum
    - sliding window를 사용하면 O(n)에 구할 수 있음