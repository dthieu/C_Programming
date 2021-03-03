// Swap 2 number, no using temp variable
void swap(int& a, int& b){
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
  /* or
  a = a + b;
  b = a - b;
  a = a - b;
  */
}
