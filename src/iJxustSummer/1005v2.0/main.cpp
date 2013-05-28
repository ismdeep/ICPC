
		for(int i=0;i<n;i++)
		{
			string tmp;
			tmp=str[i];
			if(g[tmp]==0)
			{
				g[tmp]++;
				sum++;
			}
		}

		printf("%d\n",sum);
	}
	return 0;
}

