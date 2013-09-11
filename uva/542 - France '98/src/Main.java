import java.io.FileNotFoundException;
<<<<<<< HEAD
import java.io.FileReader;
=======
>>>>>>> 02663ff90fcbab17f5eb4bac36abf682d3bb8ffc
import java.util.Scanner;


public class Main
{
	public static class Championship
	{
		public static final int level_1[] = {
			0, 2, 1, 4, 3, 6, 5, 8, 7, 10, 9, 12, 11, 14, 13, 16, 15
		};
		
		
		public static final int level_2[][] = {
			{ 0 , 0},
			
			{ 3,  4},
			{ 3,  4},
			
			{ 1,  2},
			{ 1,  2},
			
			{ 7,  8},
			{ 7,  8},
			
			{ 5,  6},
			{ 5,  6},
			
			{11, 12},
			{11, 12},
			
			{ 9, 10},
			{ 9, 10},
			
			{15, 16},
			{15, 16},
			
			{13, 14},
			{13, 14}
		};
		
		public static final int level_3[][] = {
			{ 0,  0,  0,  0},
			
			{ 5,  6,  7,  8},
			{ 5,  6,  7,  8},
			{ 5,  6,  7,  8},
			{ 5,  6,  7,  8},
			
			{ 1,  2,  3,  4},
			{ 1,  2,  3,  4},
			{ 1,  2,  3,  4},
			{ 1,  2,  3,  4},
			
			{13, 14, 15, 16},
			{13, 14, 15, 16},
			{13, 14, 15, 16},
			{13, 14, 15, 16},
			
			{ 9, 10, 11, 12},
			{ 9, 10, 11, 12},
			{ 9, 10, 11, 12},
			{ 9, 10, 11, 12}
			
		};
		
		public static final int level_4[][] = {
			{ 0,  0,  0,  0,  0,  0,  0,  0},
			
			{ 9, 10, 11, 12, 13, 14, 15, 16},
			{ 9, 10, 11, 12, 13, 14, 15, 16},
			{ 9, 10, 11, 12, 13, 14, 15, 16},
			{ 9, 10, 11, 12, 13, 14, 15, 16},
			{ 9, 10, 11, 12, 13, 14, 15, 16},
			{ 9, 10, 11, 12, 13, 14, 15, 16},
			{ 9, 10, 11, 12, 13, 14, 15, 16},
			{ 9, 10, 11, 12, 13, 14, 15, 16},
			
			{ 1,  2,  3,  4,  5,  6,  7,  8},
			{ 1,  2,  3,  4,  5,  6,  7,  8},
			{ 1,  2,  3,  4,  5,  6,  7,  8},
			{ 1,  2,  3,  4,  5,  6,  7,  8},
			{ 1,  2,  3,  4,  5,  6,  7,  8},
			{ 1,  2,  3,  4,  5,  6,  7,  8},
			{ 1,  2,  3,  4,  5,  6,  7,  8},
			{ 1,  2,  3,  4,  5,  6,  7,  8}
			
		};
		
	}
	
	public static void main(String[] args) throws FileNotFoundException 
	{
		
		//FileReader fileReader = new FileReader("in.txt");
		// TODO Auto-generated method stub
		
		@SuppressWarnings("resource")
		Scanner scanner = new Scanner(System.in);
		
		// TODO 输入16个国家、地区的名称
		String countryString[] = new String[17];
		for (int i = 1; i <= 16; i++)
		{
			countryString[i] = scanner.next();
		}
		
		// TODO 输入两两较量的胜率
		double _prob_between_2_ [][] = new double[17][17];
		for (int i = 1; i <= 16; i++)
		{
			for (int j = 1; j <= 16; j++)
			{
				int tmp;
				tmp = scanner.nextInt();
				_prob_between_2_[i][j] = (double)tmp / (double)100;
			}
		}
		
		// TODO 输出两部分输入的数据，查看调试用
		/*for (int i = 1; i <= 16; i++)
		{
			System.out.println(countryString[i]);
		}
		
		for (int i = 1; i <= 16; i++)
		{
			for (int j = 1; j <= 16; j++)
			{
				System.out.print(_prob_between_2_[i][j] + " ");
			}
			System.out.println();
		}
		*/
		// 定义比赛过程数组，第一维表示比赛的轮数，第二维才是参赛国家编号
		double round_fight[][] = new double[5][17];
		
		int round_index = 0;
		// TODO 第1轮比赛
		round_index = 1;
		for (int country_id = 1; country_id <= 16; country_id++)
		{
			round_fight[round_index][country_id] 
					= _prob_between_2_[country_id][Main.Championship.level_1[country_id]];
		}
		
		// TODO 第2轮比赛
		round_index = 2;
		for (int country_id = 1; country_id <= 16; country_id++)
		{
			double tmp_prob = 0.0;
			for (int i = 0; i < 2; i++)
			{
				tmp_prob += round_fight[round_index-1][Main.Championship.level_2[country_id][i]]
					  	  * _prob_between_2_[country_id][Main.Championship.level_2[country_id][i]];
			}
			tmp_prob *= round_fight[round_index-1][country_id];
			round_fight[round_index][country_id] = tmp_prob;
		}
		
		// TODO 第3轮比赛
		round_index = 3;
		for (int country_id = 1; country_id <= 16; country_id++)
		{
			double tmp_prob = 0.0;
			for (int i = 0; i < 4; i++)
			{
				tmp_prob += round_fight[round_index-1][Main.Championship.level_3[country_id][i]]
					  	  * _prob_between_2_[country_id][Main.Championship.level_3[country_id][i]];
			}
			tmp_prob *= round_fight[round_index-1][country_id];
			round_fight[round_index][country_id] = tmp_prob;
		}
		
		
		// TODO 第4轮比赛
		round_index = 4;
		for (int country_id = 1; country_id <= 16; country_id++)
		{
			double tmp_prob = 0.0;
			for (int i = 0; i < 8; i++)
			{
				tmp_prob += round_fight[round_index-1][Main.Championship.level_4[country_id][i]]
					  	  * _prob_between_2_[country_id][Main.Championship.level_4[country_id][i]];
			}
			tmp_prob *= round_fight[round_index-1][country_id];
			round_fight[round_index][country_id] = tmp_prob;
		}
		
		
		for (int i = 1; i <= 16; i++)
		{
			System.out.printf("%-10s p=", countryString[i]);
			System.out.printf("%.2f%%\n", round_fight[4][i] * 100);
		}
		
		
		
	}

}
