/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:16:47 by amaucher          #+#    #+#             */
/*   Updated: 2023/03/08 13:16:49 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* void handler(int num)
{
	write(STDOUT_FILENO, "I wont die!\n", 13);
}

int	main()
{
	//we want handler function to run, whenever SIGINT signal is received
	signal(SIGINT, handler);
	while(1)
	{
		printf("wasting your cycles. %d\n", getpid());
	}
} */

/* set x as a global variable */
int	x = 0;

/* we print a hint for the user */
/* we need to specify what sigusr1 is supposed to do otherwise it is just terminating the process
by default */
/* it is a bad practice to use handler functions to print sth since it 
happens in between a process, so this is just an example */
void	handle_sigusr1(int sig)
{
	/* in case x changed we just receive the signal but dont do anything */
	if (x == 0) {
	printf("\nHINT: remember that multiplication is repetitive addition\n");
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	pid = fork(); //creating two processes
	if (pid == -1){
		return 1;
	}
	if (pid == 0)
	{
		//child process
		sleep(5);
		kill(getppid(), SIGUSR1);
	}
	else {
		/* this struct is really important!! */
		struct sigaction sa;
		sa.sa_flags = SA_RESTART;
		sa.sa_handler = &handle_sigusr1;
		sigaction(SIGUSR1, &sa, NULL);
		//parent process
		printf("what is the result of 3 x 5: ");
		scanf("%d", &x);
		if (x == 15) {
			printf("Right!");
		} else {
			printf("wrong!");
		}
		//wait(NULL);
	}
	return(0);
}