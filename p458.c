int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    return (int)(log(buckets)/log(minutesToTest/minutesToDie+1)+0.999999);
}