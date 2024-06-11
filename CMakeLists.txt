cmake_minimum_required(VERSION 3.16.3)
project(DS)

# Homework source directory
set(homework_dir "${CMAKE_SOURCE_DIR}/homeworks")
set(homework_vector_dir "${CMAKE_SOURCE_DIR}/homeworks/01_vector")
set(homework_SLL_dir "${CMAKE_SOURCE_DIR}/homeworks/03_singly_linkedList")
set(homework_DLL_dir "${CMAKE_SOURCE_DIR}/homeworks/04_doubly_linkedList")
set(homework_stack_dir"${CMAKE_SOURCE_DIR}/homeworks/06_stack")
set(homework_queue_dir "${CMAKE_SOURCE_DIR}/homeworks/07_queue")
set(homework_Binary_Trees_dir "${CMAKE_SOURCE_DIR}/homeworks/08_Binary_Tree")
set(homework_BST_dir "${CMAKE_SOURCE_DIR}/homeworks/09_Binary_Search_Trees")
set(homework_Binary_Heap_dir "${CMAKE_SOURCE_DIR}/homeworks/11_AVL")
set(homework_AVL_dir "${CMAKE_SOURCE_DIR}/homeworks/12_Trie")
set(homework_Trie_dir "${CMAKE_SOURCE_DIR}/homeworks/13_Hashing")
set(homework_Hashing_dir "${CMAKE_SOURCE_DIR}/homeworks/07_queue")

# DS Implementation
# add_executable(test test.cpp)
# add_executable(vector vector.cpp)
# add_executable(singly_linkedList singly_linkedList.cpp)
# add_executable(doubly_linkedList doubly_linkedList.cpp)
# add_executable(stack stack.cpp)
# add_executable(queue queue.cpp)

# add_executable(complexity complexity.cpp)


#-----------------------------------------------------------------------------#
# DS Homeworks vector
# add_executable(HW_right_rotation ${homework_vector_dir}/right_rotation.cpp)
# add_executable(HW_left_rotation ${homework_vector_dir}/left_rotation.cpp)
# add_executable(HW_right_rotation_steps ${homework_vector_dir}/right_rotation_steps.cpp)
# add_executable(HW_del_a_pos ${homework_vector_dir}/del_a_pos.cpp)
# add_executable(HW_improved_search ${homework_vector_dir}/improved_search.cpp)

#-----------------------------------------------------------------------------#

#-------------------------- Done alhamdallah (1 - 2 - 3 - 4 - 5)--------------------------#
# DS Homeworks singly_linkedList HW1-6Easy
# add_executable( SLL_01_destructor ${homework_SLL_dir}/SLL-HW1-6Easy/01_destructor.cpp)
# add_executable( SLL_02_insert_front ${homework_SLL_dir}/SLL-HW1-6Easy/02_insert_front.cpp)
# add_executable( SLL_03_delete_front ${homework_SLL_dir}/SLL-HW1-6Easy/03_delete_front.cpp)
# add_executable( SLL_04_get_nth_from_back ${homework_SLL_dir}/SLL-HW1-6Easy/04_get_nth_back.cpp)
# add_executable( SLL_05_same_list_data ${homework_SLL_dir}/SLL-HW1-6Easy/05_is_same_list_data.cpp)
add_executable( SLL_06_linked_list_without_tail_length ${homework_SLL_dir}/SLL-HW1-6Easy/06_linked_list_without_tail_length.cpp)

#----------------------------------------------------#
# DS Homeworks singly_linkedList HW2-5Easy
# add_executable( SLL_01_delete_with_key ${homework_SLL_dir}/SLL-HW2-5Easy/01_delete_with_key.cpp)
# add_executable( SLL_02_swap_each_pair_vales ${homework_SLL_dir}/SLL-HW2-5Easy/02_swap_each_pair_vales.cpp)
# add_executable( SLL_03_reverse_list_nodes ${homework_SLL_dir}/SLL-HW2-5Easy/03_reverse_list_nodes.cpp)
# add_executable( SLL_04_delete_even_positions ${homework_SLL_dir}/SLL-HW2-5Easy/04_delete_even_positions.cpp)
# add_executable( SLL_05_insert_to_be_sorted ${homework_SLL_dir}/SLL-HW2-5Easy/05_insert_to_be_sorted.cpp)

# DS Homeworks singly_linkedList HW3-6Medium
# add_executable( SLL_01_swap_head_and_tail ${homework_SLL_dir}/SLL-HW3-6Medium/01_swap_head_and_tail.cpp)
# add_executable( SLL_02_left_rotate ${homework_SLL_dir}/SLL-HW3-6Medium/02_left_rotate.cpp)
# add_executable( SLL_03_remove_duplicates ${homework_SLL_dir}/SLL-HW3-6Medium/03_remove_duplicates.cpp)
# add_executable( SLL_04_remove_last_occurance ${homework_SLL_dir}/SLL-HW3-6Medium/04_remove_last_occurance.cpp)
# add_executable( SLL_05_move_to_back ${homework_SLL_dir}/SLL-HW3-6Medium/05_move_to_back.cpp)
# add_executable( SLL_06_recursive_max ${homework_SLL_dir}/SLL-HW3-6Medium/06_recursive_max.cpp)

# DS Homeworks singly_linkedList HW4-5Med-Hard
# add_executable(SLL_01_arrange_odd_even_nodes  ${homework_SLL_dir}/SLL-HW4-5Med-Hard/01_arrange_odd_even_nodes.cpp)
# add_executable(SLL_02_insert_alternating  ${homework_SLL_dir}/SLL-HW4-5Med-Hard/02_insert_alternating.cpp)
# add_executable(SLL_03_adding_2_huge_numbers  ${homework_SLL_dir}/SLL-HW4-5Med-Hard/03_adding_2_huge_numbers.cpp)
# add_executable(SLL_04_remove_all_repeated  ${homework_SLL_dir}/SLL-HW4-5Med-Hard/04_remove_all_repeated.cpp)
# add_executable(SLL_05_reverse_chains  ${homework_SLL_dir}/SLL-HW4-5Med-Hard/05_reverse_chains.cpp)
#-----------------------------------------------------------------------------#

# DS Homeworks doubly_linkedList HW1-4Easy-Med
# add_executable(DLL_01_delete_all_nodes_with_key ${homework_DLL_dir}/DLL-HW1-4Easy-Med/01_delete_all_nodes_with_key.cpp)
# add_executable(DLL_02_delete_even_positions ${homework_DLL_dir}/DLL-HW1-4Easy-Med/02_delete_even_positions.cpp)
# add_executable(DLL_03_delete_odd_positions ${homework_DLL_dir}/DLL-HW1-4Easy-Med/03_delete_odd_positions.cpp)
# add_executable(DLL_04_is_palindrome ${homework_DLL_dir}/DLL-HW1-4Easy-Med/04_is_palindrome.cpp)

# DS Homeworks doubly_linkedList HW2-4Med-Hard
# add_executable(DLL_01_find_the_middle ${homework_DLL_dir}/DLL-HW2-4Med-Hard/01_find_the_middle.cpp)
# add_executable(DLL_02_swap_forward_with_backward ${homework_DLL_dir}/DLL-HW2-4Med-Hard/02_swap_forward_with_backward.cpp)
# add_executable(DLL_03_reverse_list_nodes ${homework_DLL_dir}/DLL-HW2-4Med-Hard/03_reverse_list_nodes.cpp)
# add_executable(DLL_04_merge_lists ${homework_DLL_dir}/DLL-HW2-4Med-Hard/04_merge_lists.cpp)
#-----------------------------------------------------------------------------#

# DS Homeworks stack HW1-6Easy-Med
# add_executable( STK_01_student_stack ${homework_stack_dir}/Stack-HW1-6Easy_Med/01_student_stack.cpp)
# add_executable( STK_02_reverse_subwords ${homework_stack_dir}/Stack-HW1-6Easy_Med/02_reverse_subwords.cpp)
# add_executable( STK_03_reverse_number ${homework_stack_dir}/Stack-HW1-6Easy_Med/03_reverse_number.cpp)
# add_executable( STK_04_valid_paran ${homework_stack_dir}/Stack-HW1-6Easy_Med/04_valid_paran.cpp)
# add_executable( STK_05_remove_adjacent ${homework_stack_dir}/Stack-HW1-6Easy_Med/05_remove_adjacent.cpp)
# add_executable( STK_06_2stacks ${homework_stack_dir}/Stack-HW1-6Easy_Med/06_2stacks.cpp)

# DS Homeworks stack HW2-6Med_hard
# add_executable( STK_01_asteroid ${homework_stack_dir}/Stack-HW2_6Med_Hard/01_asteroid.cpp)
# add_executable( STK_02_insert_at_bottom ${homework_stack_dir}/Stack-HW2_6Med_Hard/02_insert_at_bottom.cpp)
# add_executable( STK_03_reverse ${homework_stack_dir}/Stack-HW2_6Med_Hard/03_reverse.cpp)
# add_executable( STK_04_factorial_stack ${homework_stack_dir}/Stack-HW2_6Med_Hard/04_factorial_stack.cpp)
# add_executable( STK_05_ScoreofParentheses ${homework_stack_dir}/Stack-HW2_6Med_Hard/05_ScoreofParentheses.cpp)
# add_executable( STK_06_NextGreaterElement ${homework_stack_dir}/Stack-HW2_6Med_Hard/06_NextGreaterElement.cpp)

# DS Homeworks stack HW3-5Med_hard
# add_executable( STK_01_infix_to_postfix ${homework_stack_dir}/Stack-HW3-5Med_Hard/01_infix_to_postfix.cpp)
# add_executable( STK_02_evalaute_postfix ${homework_stack_dir}/Stack-HW3-5Med_Hard/02_evalaute_postfix.cpp)
# add_executable( STK_03_infix_to_prefix ${homework_stack_dir}/Stack-HW3-5Med_Hard/03_infix_to_prefix.cpp)
# add_executable( STK_05_remove_brackets ${homework_stack_dir}/Stack-HW3-5Med_Hard/05_remove_brackets.cpp)
#-----------------------------------------------------------------------------#

# DS Homeworks queue HW1-4Easy_Med
add_executable(QU_01_deque ${homework_queue_dir}/Queue_HW1_4Easy_Med/01_deque.cpp)
# add_executable(QU_02_stack_single_queue ${homework_queue_dir}/Queue_HW1_4Easy_Med/02_stack_single_queue.cpp)
# add_executable(QU_03_queue_2stacks_o(n)_enqueue ${homework_queue_dir}/Queue_HW1_4Easy_Med/03_queue_2stacks_o(n)_enqueue.cpp)
# add_executable(QU_04_queue_2stacks_o(1)_enqueue ${homework_queue_dir}/Queue_HW1_4Easy_Med/04_queue_2stacks_o(1)_enqueue.cpp)

# DS Homeworks queue HW2-3Med_Hard
# add_executable(QU_01_priority ${homework_queue_dir}/Queue_HW2_3Med_Hard/01_priority.cpp)
# add_executable(QU_02_queue_no_added_elem ${homework_queue_dir}/Queue_HW2_3Med_Hard/02_queue_no_added_elem.cpp)
# add_executable(QU_03_numbers_stream ${homework_queue_dir}/Queue_HW2_3Med_Hard/03_numbers_stream.cpp)
#-----------------------------------------------------------------------------#

#*******************************NON_Linear_Data Structures****************************#

#-----------------------------------------------------------------------------#
# DS Homeworks BT BT_HW1_6Easy
add_executable(BT_01_tree_max ${homework_Binary_Trees_dir}/BT_HW1_6Easy/01_tree_max.cpp)
add_executable(BT_02_tree_height ${homework_Binary_Trees_dir}/BT_HW1_6Easy/02_tree_height.cpp)
add_executable(BT_03_count_all_nodes ${homework_Binary_Trees_dir}/BT_HW1_6Easy/03_count_all_nodes.cpp)
add_executable(BT_04_count_leaf_nodes ${homework_Binary_Trees_dir}/BT_HW1_6Easy/04_count_leaf_nodes.cpp)
add_executable(BT_05_search_the_tree ${homework_Binary_Trees_dir}/BT_HW1_6Easy/05_search_the_tree.cpp)
add_executable(BT_06_is_perfect ${homework_Binary_Trees_dir}/BT_HW1_6Easy/06_is_perfect.cpp)

# DS Homeworks BT BT_HW2_6Med-Hard
# add_executable(BT_ ${homework_Binary_Trees_dir}/BT_HW2_6Med-Hard/01.cpp)

# DS Homeworks BT BT_HW3_3Med-Hard
# add_executable( BT_ ${homework_Binary_Trees_dir}/BT_HW3_3Med-Hard/01.cpp)

# DS Homeworks BT BT_HW4_2Med
# add_executable(BT_ ${homework_Binary_Trees_dir}/BT_HW4_2Med/01.cpp)

# DS Homeworks BT BT_HW5_3Med
# add_executable(BT_ ${homework_Binary_Trees_dir}/BT_HW5_3Med/01.cpp)

#-----------------------------------------------------------------------------#
# DS Homeworks BST BST_HW1_2Easy
# add_executable(BST_ ${homework_BST_dir}/BST_HW1_2Easy/01.cpp)

# DS Homeworks BST BST_HW2_3Med
# add_executable( BST_ ${homework_BST_dir}/BST_HW2_3Med/01.cpp)

# DS Homeworks BST BST_HW3_3Med
# add_executable( BST_${homework_BST_dir}/BST_HW3_3Med/01.cpp)

#-----------------------------------------------------------------------------#

# DS Homeworks BH BH_HW1_5Easy_Med
# add_executable(BH_ ${homework_Binary_Heap_dir}/BH_HW1_5Easy_Med/01.cpp)

# DS Homeworks Bin_Heap BST_HW2_3Med
# add_executable( BH_ ${homework_Binary_Heap_dir}/BST_HW2_3Med/01.cpp)

#-----------------------------------------------------------------------------#
# DS Homeworks AVL AVL_HW1_7Med_Hard
# add_executable(AVL_ ${homework_AVL_dir}/AVL_HW1_7Med_Hard/01.cpp)

#-----------------------------------------------------------------------------#

# DS Homeworks Trie Trie_HW1_5Easy_Med
# add_executable(Trie_ ${homework_Trie_dir}/Trie_HW1_5Easy_Med/01.cpp)

# DS Homeworks Trie Trie_HW2_3Med
# add_executable(Trie_ ${homework_Trie_dir}/Trie_HW2_3Med/01.cpp)

# DS Homeworks Trie Trie_HW3_2Hard
# add_executable(Trie_ ${homework_Trie_dir}/Trie_HW3_2Hard/01.cpp)

#-----------------------------------------------------------------------------#

# DS Homeworks HASH Hash_HW1_5Med
# add_executable(HASH_ ${homework_Hashing_dir}/Hash_HW1_5Med/01.cpp)

# DS Homeworks HASH Hash_HW2_5Med
# add_executable(HASH_ ${homework_Hashing_dir}/Hash_HW2_5Med/01.cpp)


#-----------------------------------------------------------------------------#