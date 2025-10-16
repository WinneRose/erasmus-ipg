def classify_entity(balance_sheet_total, net_turnover, avg_employees):
    """
    Classify an entity according to Decreto-Lei n.º 158/2009

    Parameters:
    - balance_sheet_total: Total balance sheet value in euros
    - net_turnover: Net business volume in euros
    - avg_employees: Average number of employees during the period

    Returns:
    - String with entity category: "Microentity", "Small Entity",
      "Medium Entity", or "Large Entity"
    """


    MICRO_LIMITS = {
        'balance': 350000,
        'turnover': 700000,
        'employees': 10
    }

    SMALL_LIMITS = {
        'balance': 4000000,
        'turnover': 8000000,
        'employees': 50
    }

    MEDIUM_LIMITS = {
        'balance': 20000000,
        'turnover': 40000000,
        'employees': 250
    }

    # A function for counting exceeded limit amounts
    def count_exceeded_limits(balance, turnover, employees, limits):
        exceeded = 0
        if balance > limits['balance']:
            exceeded += 1
        if turnover > limits['turnover']:
            exceeded += 1
        if employees > limits['employees']:
            exceeded += 1
        return exceeded


    # Classification logic using for loop
    # An entity moves to the next category if it exceeds 2 or more limits

    categories = [
        ("Microentity", MICRO_LIMITS),
        ("Small Entity", SMALL_LIMITS),
        ("Medium Entity", MEDIUM_LIMITS)
    ]


    for category_name, limits in categories:
        exceeded = count_exceeded_limits(
            balance_sheet_total, net_turnover, avg_employees, limits
        )
        # If exceeds 0 or 1 limit, entity belongs to this category
        if exceeded <= 1:
            return category_name

    # If all categories exceeded 2 or more limits
    return "Large Entity"


def classify_entity_with_details(balance_sheet_total, net_turnover, avg_employees):

    category = classify_entity(balance_sheet_total, net_turnover, avg_employees)

    print(f"\n{'='*60}")
    print(f"ENTITY CLASSIFICATION RESULT")
    print(f"{'='*60}")
    print(f"Balance Sheet Total: €{balance_sheet_total:,.2f}")
    print(f"Net Turnover: €{net_turnover:,.2f}")
    print(f"Average Employees: {avg_employees}")
    print(f"\nClassification: {category.upper()}")
    print(f"{'='*60}\n")

    return category


def get_valid_number(prompt, value_type="float"):

    while True:
        try:
            user_input = input(prompt)
            if value_type == "float":
                return float(user_input)
            elif value_type == "int":
                return int(user_input)
        except ValueError:
            print("Invalid input! Please enter a valid number.")


def test_cases():
    """
    Run all test cases from the document
    """
    print("\n" + "="*60)
    print("ENTITY CLASSIFICATION SYSTEM - TEST CASES")
    print("According to Decreto-Lei n.º 158/2009")
    print("="*60 + "\n")

    # Case 1: Microentity from document
    print("TEST CASE 1 (From Document):")
    print("Expected: MICROENTITY")
    classify_entity_with_details(91365.97, 150494.43, 2)

    # Case 2: Medium Entity from document
    print("TEST CASE 2 (From Document):")
    print("Expected: MEDIUM ENTITY")
    classify_entity_with_details(9227525.70, 9271245.81, 53)

    # Case A: Microentity (0 limits exceeded)
    print("TEST CASE A:")
    print("Expected: MICROENTITY (0 limits exceeded)")
    classify_entity_with_details(200000, 500000, 6)

    # Case B: Microentity (1 limit exceeded)
    print("TEST CASE B:")
    print("Expected: MICROENTITY (1 limit exceeded - balance)")
    classify_entity_with_details(400000, 650000, 8)

    # Case C: Small Entity (0 limits exceeded)
    print("TEST CASE C:")
    print("Expected: SMALL ENTITY (0 limits exceeded)")
    classify_entity_with_details(3500000, 6000000, 30)

    # Case D: Small Entity (1 limit exceeded)
    print("TEST CASE D:")
    print("Expected: SMALL ENTITY (1 limit exceeded - balance)")
    classify_entity_with_details(4500000, 7500000, 45)

    # Case E: Large Entity (2 small limits exceeded)
    print("TEST CASE E:")
    print("Expected: LARGE ENTITY (2 small limits exceeded)")
    classify_entity_with_details(2000000, 9000000, 55)

    # Case F: Large Entity (2 small limits exceeded)
    print("TEST CASE F:")
    print("Expected: LARGE ENTITY (2 limits exceeded)")
    classify_entity_with_details(5000000, 10000000, 35)

    # Case G: Large Entity (3 medium limits exceeded)
    print("TEST CASE G:")
    print("Expected: LARGE ENTITY (3 limits exceeded)")
    classify_entity_with_details(40000000, 60000000, 500)

    # Case with 11 employees (Microentity - 1 limit exceeded)
    print("TEST CASE - 11 Employees:")
    print("Expected: MICROENTITY (1 limit exceeded - employees)")
    classify_entity_with_details(300000, 600000, 11)

    # Case with 51 employees (Microentity - 1 limit exceeded)
    print("TEST CASE - 51 Employees:")
    print("Expected: MICROENTITY (1 limit exceeded - employees)")
    classify_entity_with_details(300000, 600000, 51)

    # Case with 251 employees (Microentity - 1 limit exceeded)
    print("TEST CASE - 251 Employees:")
    print("Expected: MICROENTITY (1 limit exceeded - employees)")
    classify_entity_with_details(300000, 600000, 251)

    # Small Entity that exceeds micro limits (turnover + employees)
    print("TEST CASE - Small Entity (exceeds micro turnover + employees):")
    print("Expected: SMALL ENTITY")
    classify_entity_with_details(300000, 800000, 15)

    print("\n" + "="*60)
    print("ALL TEST CASES COMPLETED")
    print("="*60 + "\n")


def main():

    print("\n" + "="*60)
    print("ENTITY CLASSIFICATION SYSTEM")
    print("According to Decreto-Lei n.º 158/2009")
    print("="*60 + "\n")

    print("Choose an option:")
    print("1 - Run test cases")
    print("2 - Enter entity information manually")

    choice = input("\nEnter your choice (1 or 2): ").strip()

    if choice == "1":
        test_cases()
    elif choice == "2":
        while True:
            print("\nPlease enter the entity information:")
            print("-" * 40)

            # Get user inputs
            balance = get_valid_number("Balance Sheet Total (€): ", "float")
            turnover = get_valid_number("Net Turnover (€): ", "float")
            employees = get_valid_number("Average Number of Employees: ", "int")

            # Classify the entity
            classify_entity_with_details(balance, turnover, employees)

            # Ask if user wants to continue
            print("\nDo you want to classify another entity?")
            continue_choice = input("Enter 'y' for yes, any other key to exit: ").lower()

            if continue_choice != 'y':
                print("\n" + "="*60)
                print("Thank you for using the Entity Classification System!")
                print("="*60 + "\n")
                break
    else:
        print("Invalid choice! Please run the program again.")

if __name__ == "__main__":
    main()