var maxScore = function(C, K) {
    let total = 0
    for (let i = 0; i < K; i++) total += C[i]
    let best = total
    for (let i = K - 1, j = C.length - 1; ~i; i--, j--)
        total += C[j] - C[i], best = Math.max(best, total)
    return best
};