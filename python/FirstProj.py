def cost_calculator(*pizzas, **sides):
    total_cost = 0.00
    toppings_dict = {
        "pepperoni" : 1,
        "mushroom" : 0.5,
        "olive" : 0.5,
        "anchovy" : 2,
        "ham" : 1.5
    }
    drinks_dict = {
        "small" : 2,
        "medium" : 3,
        "large" : 3.5,
        "tub" : 3.75
    }
    wings_dict = {
        10 : 5,
        20 : 9,
        40 : 17.5,
        100 : 48
    }
    for pizza in pizzas:
        cost = 13.0
        for i in range(0, len(pizza)):
            cost += toppings_dict[pizza[i]]
        total_cost += cost 
    deducted = 0.0
    for arg in sides:
        if (arg == "wings") :
            for i in sides[arg]:
                total_cost += wings_dict[i]
        elif (arg == "drinks") :
            for i in sides[arg]:
                total_cost += drinks_dict[i]
        elif (arg == "coupon") :
            deducted = total_cost * (sides[arg])
            
    tax = total_cost * 0.0625
    return (round(total_cost + tax - deducted, 2))


print(cost_calculator([], ["ham", "anchovy"], drinks=["tub", "tub"], coupon=0.1))
