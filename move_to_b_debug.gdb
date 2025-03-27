# move_to_b_debug.gdb - GDB script for debugging the move_to_b function

# Define a function to print a linked list
define print_list
    set $node = $arg0
    set $index = 0
    set $limit = 20
    if $node == 0
        printf "Empty list\n"
    else
        printf "["
        while $node && $index < $limit
            if $index > 0
                printf ", "
            end
            printf "%d", $node->content
            set $node = $node->next
            set $index = $index + 1
        end
        if $node != 0
            printf ", ... (more elements)"
        end
        printf "]\n"
    end
end

# Define a function to display the current state
define show_state
    printf "\n--- Iteration %d ---\n", $iteration
    printf "stack_a: "
    print_list *$stack_a
    printf "stack_a size: %d\n", ft_lstsize(*$stack_a)
    
    printf "stack_b: "
    print_list *$stack_b
    printf "stack_b size: %d\n", ft_lstsize(*$stack_b)
    
    printf "start: %d, end: %d\n", *$start, *$end
    printf "tab[start]: %d, tab[end]: %d\n", $tab[*$start], $tab[*$end]
    
    printf "Current condition: "
    if *$stack_a
        if (*$stack_a)->content <= $tab[*$end] && (*$stack_a)->content > $tab[*$start]
            printf "(*stack_a)->content <= tab[*end] && (*stack_a)->content > tab[*start]\n"
        else if (*$stack_a)->content <= $tab[*$start]
            printf "(*stack_a)->content <= tab[*start]\n"
        else if (*$stack_a)->content > $tab[*$end]
            printf "(*stack_a)->content > tab[*end]\n"
        else
            printf "Unknown condition\n"
        end
        printf "(*stack_a)->content = %d\n", (*$stack_a)->content
    else
        printf "stack_a is empty\n"
    end
    printf "------------------\n\n"
end

# Define a function to monitor operations
define monitor_operation
    if $prev_stack_a_size > ft_lstsize(*$stack_a)
        printf "Operation: push_b\n"
    else if $prev_stack_a_size < ft_lstsize(*$stack_a)
        printf "Operation: push_a\n"
    else if $prev_stack_a_top != 0 && *$stack_a != 0 && $prev_stack_a_top != (*$stack_a)->content
        printf "Operation: rotate_a or swap_a\n"
    else if $prev_stack_b_top != 0 && *$stack_b != 0 && $prev_stack_b_top != (*$stack_b)->content
        printf "Operation: rotate_b or swap_b\n"
    end
end

# Set a breakpoint at the start of move_to_b
break move_to_b
commands
    silent
    printf "\n======= Starting move_to_b =======\n"
    set $stack_a = stack_a
    set $stack_b = stack_b
    set $start = start
    set $end = end
    set $tab = tab
    set $iteration = 0
    
    printf "Initial state:\n"
    show_state
    
    # Continue to the beginning of the while loop
    break move_to_b:10
    continue
end

# Set a breakpoint at the beginning of the while loop
break move_to_b:10
commands
    silent
    if *$start >= ft_lstsize(*$stack_a) || ft_lstsize(*$stack_a) <= 0
        printf "Loop condition failed, exiting the loop\n"
        continue
    end
    
    set $iteration = $iteration + 1
    set $prev_stack_a_size = ft_lstsize(*$stack_a)
    set $prev_stack_b_size = ft_lstsize(*$stack_b)
    set $prev_stack_a_top = (*$stack_a != 0) ? (*$stack_a)->content : 0
    set $prev_stack_b_top = (*$stack_b != 0) ? (*$stack_b)->content : 0
    
    show_state
end

# Set breakpoints at each operation to monitor them
break push_b
commands
    silent
    printf "Executing: push_b\n"
    continue
end

break swap_b
commands
    silent
    printf "Executing: swap_b\n"
    continue
end

break rotate_a
commands
    silent
    printf "Executing: rotate_a\n"
    continue
end

break rotate_b
commands
    silent
    printf "Executing: rotate_b\n"
    continue
end

# Set a breakpoint at the end of each iteration (start/end incrementation)
break move_to_b:34
commands
    silent
    printf "End of iteration %d\n", $iteration
    if *$end == ft_lstsize(*$stack_a) - 1
        printf "Updated start: %d\n", *$start + 1
    else
        printf "Updated start: %d, end: %d\n", *$start + 1, *$end + 1
    end
    continue
end

# Set a breakpoint at the end of the function
break move_to_b:36
commands
    silent
    printf "\n======= Finished move_to_b =======\n"
    printf "Final state:\n"
    show_state
    printf "Total iterations: %d\n", $iteration
    continue
end

# Define a user command to step through one iteration
define next_iter
    set $old_iteration = $iteration
    continue
    # Wait until iteration changes or the function exits
    while $old_iteration == $iteration && $pc >= &move_to_b && $pc < &move_to_b + 200
        continue
    end
end

# Print usage instructions
printf "\nDebugging move_to_b function\n"
printf "Commands available:\n"
printf "  continue - Run until the next breakpoint\n"
printf "  next_iter - Run a single iteration of the loop\n"
printf "  show_state - Show current state of stacks and variables\n"
printf "  print_list *stack_a - Print stack_a\n"
printf "  print_list *stack_b - Print stack_b\n\n"
printf "Start by running 'continue' to begin debugging\n"