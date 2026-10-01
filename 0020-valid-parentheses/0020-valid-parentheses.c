bool isValid(char* s)
{
    char stack[10000];
    int top = -1;
    int i;

    for (i = 0; s[i] != '\0'; i++)
    {
        // Opening brackets
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            stack[++top] = s[i];
        }

        // Closing brackets
        else
        {
            // Stack is empty
            if (top == -1)
                return false;

            // Check matching brackets
            if (s[i] == ')' && stack[top] != '(')
                return false;

            if (s[i] == '}' && stack[top] != '{')
                return false;

            if (s[i] == ']' && stack[top] != '[')
                return false;

            // Pop
            top--;
        }
    }

    // Stack should be empty
    return top == -1;
}