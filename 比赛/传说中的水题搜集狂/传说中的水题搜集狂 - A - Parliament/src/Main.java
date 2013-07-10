import java.util.Scanner;



public class Main
{
	public static final int NULL = -1;
	/** This is class BinTreeNode. */
	public class BinTreeNode
	{
		public int left_index;
		public int right_index;
		public int m_value;
		
		public BinTreeNode()
		{
			this.left_index = NULL;
			this.right_index = NULL;
			this.m_value = NULL;
		}
		
	}
	
	public class BinTree
	{
		public static final int NODE_MAX = 6600;
		public Main.BinTreeNode bin_node[] = new Main.BinTreeNode[NODE_MAX];
		
		private int shift_index = 0;
		
		public int pre_load_value [] = new int[NODE_MAX];
		public int pre_load_count;
		
		
		public void show_map ()
		{
			System.out.println("---------------------------------------------");
			for (int i = 0; i < pre_load_count; i++)
			{
				System.out.println(" --> " + bin_node[i].left_index + "--" + bin_node[i].right_index + " : " + bin_node[i].m_value);
			}
			System.out.println("---------------------------------------------");
		}
		
		public void procedure_insert_manager (int from_index, int to_index)
		{
			this.insert_item(pre_load_value[to_index], 0);
			//System.out.print(bin_node[to_index].m_value);
			
			
			int min_right = from_index - 1;
			while (pre_load_value[min_right+1] < pre_load_value[to_index])
			{
				min_right++;
			}
			
			
			if (min_right < to_index - 1)
			{
				this.procedure_insert_manager(min_right + 1, to_index - 1);
			}
			
			if (min_right >= from_index)
			{
				this.procedure_insert_manager(from_index, min_right);
			}
			
		}
		
		public void init_bin_tree_node ()
		{
			for (int i = 0; i < NODE_MAX; i++)
			{
				bin_node[i] = new Main().new BinTreeNode();
			}
		}
		
		public void insert_item (int insert_value, int insert_index)
		{
			if (
				   NULL == bin_node[insert_index].left_index 
				&& NULL == bin_node[insert_index].right_index
				&& NULL == bin_node[insert_index].m_value
			)
			{
				bin_node[insert_index].m_value = insert_value;
			}
			else
			{
				if (insert_value < bin_node[insert_index].m_value)
				{
					/** Insert current value at left_index of insert_index.  */
					if (NULL == bin_node[insert_index].left_index)
					{
						shift_index++;
						bin_node[insert_index].left_index = shift_index;
						insert_item(insert_value, bin_node[insert_index].left_index);
					}
					else 
					{
						insert_item(insert_value, bin_node[insert_index].left_index);
					}
				}
				else
				{
					/** Insert current value at right_index of insert_index. */
					if (NULL == bin_node[insert_index].right_index)
					{
						shift_index++;
						bin_node[insert_index].right_index = shift_index;
						insert_item(insert_value, bin_node[insert_index].right_index);
					}
					else
					{
						insert_item(insert_value, bin_node[insert_index].right_index);
					}
				}
			}
		}
		
		public void show_by_right_left_root(int show_index)
		{
			if (NULL != bin_node[show_index].right_index)
			{
				show_by_right_left_root(bin_node[show_index].right_index);
			}
			if (NULL != bin_node[show_index].left_index)
			{
				show_by_right_left_root(bin_node[show_index].left_index);
			}
			
			System.out.print(bin_node[show_index].m_value + " ");
		}
		
	}
	
	public static void main(String[] args)
	{
		//System.out.println("-- debug --");
		@SuppressWarnings("resource")
		Scanner scanner = new Scanner(System.in);
		while (scanner.hasNext())
		{
			int n;
			n = scanner.nextInt();
			Main.BinTree bin_tree = new Main().new BinTree();
			bin_tree.init_bin_tree_node();
			
			
			for (int i = 0; i < n; i++)
			{
				bin_tree.pre_load_value[i] = scanner.nextInt();
			}
			
			bin_tree.pre_load_count = n;
			bin_tree.procedure_insert_manager(0, n - 1);
			bin_tree.show_by_right_left_root(0);
			System.out.println();
		}
	}
}
