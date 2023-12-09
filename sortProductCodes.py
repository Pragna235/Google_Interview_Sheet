def sortProductCodes(order, productCodes):
    # Write your code here
    return sorted(productCodes, key=lambda x:[order.index(i) for i in x])
