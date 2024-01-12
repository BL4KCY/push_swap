void	print(void *content)
{
	ft_putnbr_fd(*(int *)content, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}


